#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list 
make_empty_list()
{
	list l = malloc(sizeof(struct node));
	l->e = 0;
	l->next = NULL;
    return l;
}

int 
is_empty(list l)
{
    return l->next == NULL;
}

int
is_last(position p, list l)
{
    return p->next == NULL;
}

position
find(element e, list l)
{
	position p;

	p = l->next;
	while (p != NULL)
	{
		if (p->e == e)
			return p;
		p = p->next;
	};
}

int
insert(element e, list l)
{
	position p;

	p = l;
	while (p->next != NULL)
		p = p->next;

    p->next = malloc(sizeof(struct node));
	if (p->next != NULL)
	{
		p->next->e = e;
		p->next->next = NULL;
		return 0;
	}

	return -1;
}

int
delete(element e, list l)
{
	position pre;
	position p;

	pre = l;
	p = pre->next;
	while (p != NULL)
	{
		if (p->e == e)
		{
			pre->next = p->next;
			free(p);
			return 0;
		}
		pre = p;
		p = p->next;
	};

	return -1;
}

int 
delete_list(list l)
{
	position p;
	position next;

	p = l;
	next = p->next;
	free(p);
	while (next != NULL)
	{
		p = next;
		next = p->next;
		free(p);
	};

	return 0;
}

int
main()
{
	int i;
	list l;

    l = make_empty_list();
	if (is_empty(l) == 1)
		printf("get a empty list\n");
	else
		printf("get a not empty list\n");

	for (i = 0;i < 100;i++)
	{
		if (insert(i, l) == -1)
			printf("insert element %d fail\n", i);
	}

	printf("11 is %s!\n", (find(11 ,l) == NULL) ? "not exist" : "exist");
	delete_list(l);
	printf("11 is %s!\n", (find(11 ,l) == NULL) ? "not exist" : "exist");

    return 1;
}
