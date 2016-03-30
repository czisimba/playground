#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>

static int exit_signal = SIGUSR1;
static const char *lockfile = "/home/tesla/file_lock_test.pid";

int main(int argc, char **argv)
{
	int res = 0;
	int lfd;
	char pids[10];
	struct flock lock;

	res = lfd = open(lockfile, O_WRONLY|O_CREAT, 0644);
	if(res == -1) {
		printf("Could not open lockfile");
        exit(-1);
	}
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = 0;
	fcntl(lfd, F_GETLK, &lock);
	close(lfd);

    if (lock.l_pid && !kill(lock.l_pid, 0)) {
        res = 0;
        if (kill(lock.l_pid, exit_signal) < 0) {
            printf("Could not deliver signal %d to pid %d", exit_signal, lock.l_pid);
            res = -1;
        }
    }
	unlink(lockfile);
	// now open the lockfile and place the lock
	res = lfd = open(lockfile, O_WRONLY|O_CREAT|O_TRUNC|O_EXCL, 0644);
	if(res < 0) {
		printf("Could not open lockfile");
        exit(-1);
	}
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	if ((res = fcntl(lfd, F_SETLK, &lock)) < 0) {
		printf("lock pidfile fail!");
	}
	sprintf(pids, "%d", getpid());
	if ((size_t)(res = write(lfd, pids, strlen(pids))) != strlen(pids)) {
		printf("Could not write pidfile!");
		if(res >= 0)
			res = -2;
        exit(-1);
	}

    sleep(30);

    exit(0);
}
