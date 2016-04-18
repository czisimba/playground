#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* l = NULL, *head;
    if (l1 == NULL && l2 == NULL)
        return NULL;

    if (l2 == NULL)
    {
        head = l1;
        l1 = l1->next;
    } else if (l1 == NULL)
    {
        head = l2;
        l2 = l2->next;
    } else if (l1->val < l2->val) {
        head = l1;
        l1 = l1->next;
    } else {
        head = l2;
        l2 = l2->next;
    }
    l = head;

    while (l1 != NULL || l2 != NULL)
    {
        if (l2 == NULL)
        {
            l->next = l1;
            l = l1;
            l1 = l1->next;
        } else if (l1 == NULL)
        {
            l->next = l2;
            l = l2;
            l2 = l2->next;
        } else if (l1->val < l2->val) {
            l->next = l1;
            l = l1;
            l1 = l1->next;
        } else {
            l->next = l2;
            l = l2;
            l2 = l2->next;
        }
    }

    return head;
}

int main()
{
    struct ListNode l1,l2, *ll;
    l1.val = 1;
    l1.next = NULL;
    l2.val = 2;
    l2.next = NULL;
    ll = mergeTwoLists(&l1, &l2);
    //ll = mergeTwoLists(NULL, &l2);
    //ll = mergeTwoLists(&l1, NULL);

    while (ll != NULL)
    {
        printf("val is [%d]\n", ll->val);
        ll = ll->next;
    }

    return 0;
}
