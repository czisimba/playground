#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s *next;
}node_t;

typedef struct queue_s {
    node_t *first,*rear;
}queue_t;

queue_t *insert_queue(queue_t *q, int x)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = x;
    new_node->next = NULL;
    if (q->first == NULL)
    {
        q->first = new_node;
        q->rear = new_node;
    }
    else {
        q->rear->next = new_node;
        q->rear = new_node;
    }

    return q;
}

queue_t *delete_queue(queue_t *q)
{
    if (q->first == NULL)
    {
        //empty queue
    }
    else if (q->first == q->rear)
    {
        free(q->first);
        q->first = q->rear = NULL;
    }
    else
    {
        node_t *p = q->first;
        q->first = q->first->next;
        free(p);
    }

    return q;
}

void print_queue(queue_t *q)
{
    node_t *p = q->first;
    printf("-----print queue-----\n");
    while (p != NULL)
    {
        printf("data[%d] in queue\n", p->data);
        p = p->next;
    }
}

int main()
{
    queue_t q;
    q.first = NULL;
    q.rear = NULL;
    for (int i = 0;i < 10;++i)
    {
        insert_queue(&q, i);
    }
    print_queue(&q);
    delete_queue(&q);
    delete_queue(&q);
    delete_queue(&q);
    print_queue(&q);

    return 0;
}
