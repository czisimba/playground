#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s *next;
}node_t;

void JOSEPHUS(int n,int k,int m)
{
    node_t *p,*q,*head,*new_node;

    head = (node_t *)malloc(sizeof(node_t));
    head->data = 1;
    head->next = head;
    p = head;
    for (int i = 1;i < n;++i)
    {
        new_node = (node_t *)malloc(sizeof(node_t));
        new_node->data = i + 1;
        new_node->next = p->next;
        p->next = new_node;
        p = new_node;
    }
    q = p;// k == 1
    p = head;
    while (--k) q = p,p = p->next;
    while (n--)
    {
        for (int s = m - 1;s--;q = p,p = p->next);
        q->next = p->next;
        printf("delete data:[%d]\n", p->data);
        free(p);
        p = q->next;
    }
}


int main()
{
    JOSEPHUS(18,5,13);

    return 0;
}
