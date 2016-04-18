#include <stdio.h>
#include <stdlib.h>
#include "list.h"

node_t *create_list()
{
    int x,head_init = 0;
    node_t *p,*s;
    node_t *head = (node_t *)malloc(sizeof(node_t));
    head->next = NULL;
    p = head;
    do {
        printf("please input the data:\n");
        scanf("%d", &x);
        if (x != 0)
        {
            if (head_init == 0)
            {
                head->data = x;
                head_init = 1;
            }
            else
            {
                s = (node_t *)malloc(sizeof(node_t));
                s->next = NULL;
                s->data = x;
                p->next = s;
                p = s;
            }
        }
    } while(x != 0);

    return head;
}

int get_list_length(node_t *head)
{
    int length = 0;
    node_t *p = head;
    while (p != NULL)
    {
        length++;
        p = p->next;
    }

    return length;
}

void print_list(node_t *head)
{
    int count = 0;
    node_t *p = head;
    printf("------print list nodes now:------\n");
    while (p != NULL)
    {
        count++;
        printf("node count:[%d], data is [%d]\n", count, p->data);
        p = p->next;
    }
}

node_t *delete_node(node_t *head, int data)
{
    node_t *p = head,*q;
    while (p != NULL)
    {
        if (p->data == data)
        {
            if (p == head)
            {
                head = head->next;
                free(p);
            }
            else {
                q->next = p->next;
                free(p);
            }
            return head;
        }
        q = p;
        p = p->next;
    }

    return head;
}

node_t *insert_node(node_t *head, int data)
{
    node_t *p = head,*q, *new_node;
    new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    while (p != NULL)
    {
        if (data < p->data)
        {
            if (p == head)
            {
                new_node->next = head;
                head = new_node;
            }
            else {
                new_node->next = p;
                q->next = new_node;
            }
            return head;
        }
        q = p;
        p = p->next;
    }
    q->next = new_node;
    new_node->next = NULL;

    return head;
}

void sort_list(node_t *head)
{
    int data;
    node_t *i_node,*j_node,*min_node;

    i_node = head;
    while (i_node != NULL)
    {
        min_node = i_node;
        j_node = i_node->next;
        while (j_node != NULL)
        {
            if (j_node->data < min_node->data)
                min_node = j_node;
            j_node = j_node->next;
        }
        data = i_node->data;
        i_node->data = min_node->data;
        min_node->data = data;
        i_node = i_node->next;
    }
}

int main()
{
    node_t *list;
    int length = 0;

    list = create_list();

    length = get_list_length(list);
    printf("get list length is [%d]\n", length);

    print_list(list);
    sort_list(list);
    print_list(list);
    list = insert_node(list, 3);
    print_list(list);
    list = delete_node(list, 3);
    print_list(list);

    return 0;
}
