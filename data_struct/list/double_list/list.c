#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s *prev;
    struct node_s *next;
}node_t;

node_t *create_list()
{
    int head_init = 0;
    int x;
    node_t *head = (node_t *)malloc(sizeof(node_t));
    node_t *p = head, *p0;
    do {
        printf("please input a number:\n");
        scanf("%d", &x);
        if (x != 0)
        {
            if (head_init == 0)
            {
                head->data = x;
                head->prev = NULL;
                head->next = NULL;
                head_init = 1;
            }
            else {
                p0 = (node_t *)malloc(sizeof(node_t));
                p0->data = x;
                p->next = p0;
                p0->prev = p;
                p0->next = NULL;
                p = p->next;
            }
        }
    } while(x != 0);

    return head;
}

void print_list(node_t *head)
{
    int count = 0;
    node_t *p = head,*q;

    printf("-----print list-----\n");
    while (p != NULL)
    {
        count++;
        printf("node count[%d],data[%d]\n", count, p->data);
        if (p->next == NULL)
            q = p;
        p = p->next;
    }

    while (q != NULL)
    {
        printf("node count[%d],data[%d]\n", count, q->data);
        q = q->prev;
        count--;
    }
}

node_t *delete_list(node_t *head, int data)
{
    node_t *p = head;
    while (p->data != data && p->next != NULL)
        p = p->next;

    if (p->data == data)
    {
        if (p == head)
        {
            if (head->next != NULL)
            {
                head->next->prev = NULL;
                head = head->next;
                free(p);
            }
            else {
                head->data = 0;
            }
        }
        else {
            if (p->next != NULL)
            {
                p->prev->next = p->next;
                p->next->prev = p->prev;
            }
            else {
                p->prev->next = NULL;
            }
            free(p);
        }
    }

    return head;
}

int main()
{
    node_t *list;
    list = create_list();
    print_list(list);
    list = delete_list(list, 3);
    print_list(list);

    return 0;
}

