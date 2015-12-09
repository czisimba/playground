typedef int element;
struct node 
{
    element e;
    struct node *next;
};

typedef struct node * node_ptr;
typedef node_ptr list;
typedef node_ptr position;
