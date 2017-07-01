#ifndef __ADDTWONUMBERS__
#define __ADDTWONUMBERS__

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
void pushLinkedList(ListNode **l1,int val);
int getNumberLinkedList(ListNode *l1);

#endif