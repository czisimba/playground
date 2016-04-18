#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s *next;
}node_t;

typedef struct my_stack_s {
    node_t *bottom,*top;
}my_stack_t;

my_stack_t *push(my_stack_t *s, int data)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    if (s->top == NULL)
    {
        s->top = new_node;
        s->bottom = new_node;
    }
    else {
        new_node->next = s->top;
        s->top = new_node;
    }

    return s;
}

my_stack_t *pop(my_stack_t *s)
{
    if (s->top == NULL)
    {
        //... empty stack
    }
    else if (s->top == s->bottom)
    {
        free(s->top);
        s->top = NULL;
        s->bottom = NULL;
    }
    else 
    {
        node_t *q = s->top;
        s->top = s->top->next;
        free(q);
    }

    return s;
}

void print_queue(my_stack_t *s)
{
    node_t *p = s->top;
    printf("-----stack-----\n");
    while (p != NULL)
    {
        printf("data[%d] in stack\n", p->data);
        p = p->next;
    }

}

int main()
{
    int i;
    my_stack_t s;
    s.bottom = NULL;
    s.top = NULL;
    for (i = 0;i < 10;++i)
        push(&s, i);
    print_queue(&s);
    for (i = 0;i < 10;++i)
        pop(&s);
    print_queue(&s);

    return 0;
}
