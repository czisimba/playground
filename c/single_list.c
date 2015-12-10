#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_t {
    int element;
    struct node_t *next;
} node;

typedef struct head_t {
    int node_num;
    node *first;
} head;

head *init()
{
    head *list = malloc(sizeof(head));
    memset(list, 0 ,sizeof(head));
    return list;
}

int insert(head *list)
{
    if (list == NULL)
        return -1;

    if (list->first == NULL)
    {
        list->first = malloc(sizeof(node)); 
        memset(list->first, 0 ,sizeof(node));
        list->first->element = 1;
    }
    else
    {
        node *pre = NULL;
        node *nd = list->first; 
        while (nd != NULL)
        {
            pre = nd;
            nd = nd->next;
        }
        pre->next = malloc(sizeof(node));
        memset(pre->next, 0 ,sizeof(node));
        pre->next->element = pre->element + 1;
    }
    
    return 0;
}

int print_list(head *list)
{
    int cnt = 0;
    if (list == NULL)
        return -1;

    node *nd = list->first; 
    while (nd != NULL)
    {
        cnt++;
        printf("node[%d] element is %d\n", cnt, nd->element);
        nd = nd->next;
    }

    return 0;
}

int main()
{
    int i;
    head *list;

    list = init();
    for (i = 0;i < 100;i++)
        insert(list);
    print_list(list);

    return 0;
}
