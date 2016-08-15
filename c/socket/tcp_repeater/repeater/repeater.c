#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <netinet/in.h>

#include "socket.h"

static uint16_t listen_port = 0;
static uint16_t device_port = 0;

struct client_data {
	int fd;
	int sfd;
	volatile int stop_ctos;
	volatile int stop_stoc;
};

static void *run_stoc_loop(void *arg)
{
	struct client_data *cdata = (struct client_data*)arg;
	int recv_len;
	int sent;
	char buffer[131072];

	printf("%s: fd = %d\n", __func__, cdata->fd);

	while (!cdata->stop_stoc && cdata->fd > 0 && cdata->sfd > 0) {
		recv_len = socket_receive_timeout(cdata->sfd, buffer, sizeof(buffer), 0, 5000);
		if (recv_len <= 0) {
			if (recv_len == 0) {
				// try again
				continue;
			} else {
				fprintf(stderr, "stoc recv failed: %s\n", strerror(-recv_len));
				break;
			}
		} else {
			// send to socket
			sent = socket_send(cdata->fd, buffer, recv_len);
			if (sent < recv_len) {
				if (sent <= 0) {
					fprintf(stderr, "send failed: %s\n", strerror(errno));
					break;
				} else {
					fprintf(stderr, "only sent %d from %d bytes\n", sent, recv_len);
				}
			}
		}
	}

	socket_close(cdata->fd);

	cdata->fd = -1;
	cdata->stop_ctos = 1;

	return NULL;
}

static void *run_ctos_loop(void *arg)
{
	struct client_data *cdata = (struct client_data*)arg;
	int recv_len;
	int sent;
	char buffer[131072];
	pthread_t stoc;

	printf("%s: fd = %d\n", __func__, cdata->fd);

	cdata->stop_stoc = 0;
	pthread_create(&stoc, NULL, run_stoc_loop, cdata);

	while (!cdata->stop_ctos && cdata->fd>0 && cdata->sfd>0) {
		recv_len = socket_receive_timeout(cdata->fd, buffer, sizeof(buffer), 0, 5000);
		if (recv_len <= 0) {
			if (recv_len == 0) {
				// try again
				continue;
			} else {
				fprintf(stderr, "ctos recv failed: %s\n", strerror(-recv_len));
				break;
			}
		} else {
			// send to local socket
			sent = socket_send(cdata->sfd, buffer, recv_len);
			if (sent < recv_len) {
				if (sent <= 0) {
					fprintf(stderr, "send failed: %s\n", strerror(errno));
					break;
				} else {
					fprintf(stderr, "only sent %d from %d bytes\n", sent, recv_len);
				}
			}
		}
	}

	socket_close(cdata->fd);

	cdata->fd = -1;
	cdata->stop_stoc = 1;

	pthread_join(stoc, NULL);

	return NULL;
}

static void *acceptor_thread(void *arg)
{
	struct client_data *cdata;
	pthread_t ctos;

	if (!arg) {
		fprintf(stderr, "invalid client_data provided!\n");
		return NULL;
	}

	cdata = (struct client_data*)arg;

    cdata->sfd = socket_connect("127.0.0.1", device_port);
	if (cdata->sfd < 0) {
		fprintf(stderr, "Error connecting to device!\n");
	} else {
		cdata->stop_ctos = 0;

		pthread_create(&ctos, NULL, run_ctos_loop, cdata);
		pthread_join(ctos, NULL);
	}

	if (cdata->fd > 0) {
		socket_close(cdata->fd);
	}
	if (cdata->sfd > 0) {
		socket_close(cdata->sfd);
	}
	free(cdata);

	return NULL;
}


int main(int argc, char **argv)
{
	int mysock = -1;

	if (argc < 3) {
		printf("usage: %s LOCAL_TCP_PORT DEVICE_TCP_PORT [UDID]\n", argv[0]);
		return 0;
	}

	listen_port = atoi(argv[1]);
	device_port = atoi(argv[2]);

	if (!listen_port) {
		fprintf(stderr, "Invalid listen_port specified!\n");
		return -EINVAL;
	}

	if (!device_port) {
		fprintf(stderr, "Invalid device_port specified!\n");
		return -EINVAL;
	}

	// first create the listening socket endpoint waiting for connections.
	mysock = socket_create(listen_port);
	if (mysock < 0) {
		fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
		return -errno;
	} else {
		pthread_t acceptor;
		struct client_data *cdata;
		int c_sock;
		while (1) {
			printf("waiting for connection\n");
			c_sock = socket_accept(mysock, listen_port);
			if (c_sock) {
				printf("accepted connection, fd = %d\n", c_sock);
				cdata = (struct client_data*)malloc(sizeof(struct client_data));
				if (!cdata) {
					socket_close(c_sock);
					fprintf(stderr, "ERROR: Out of memory\n");
					return -1;
				}
				cdata->fd = c_sock;
				pthread_create(&acceptor, NULL, acceptor_thread, cdata);
				pthread_detach(acceptor);
			} else {
				break;
			}
		}
		socket_close(c_sock);
		socket_close(mysock);
	}

	return 0;
}
