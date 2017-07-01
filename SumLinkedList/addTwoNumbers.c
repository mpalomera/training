#include <stdlib.h>
#include <stdio.h>
#include "addTwoNumbers.h"

/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/


//Assuming that the numbers are big enough and they don't fit on a unsigned integer
//This is no needed since the list are order on reverse order, it can be added directly
//Need to found what is the longer number ???
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *bl1 = l1, *bl2 = bl2;
    ListNode *l3;
    l3 = createLinkedList();
    while(l1->next != NULL && l2->next  != NULL) {
        //Add the two numbers
    }


}

ListNode *createLinkedList(void)
{
    ListNode *ln = (ListNode *)malloc(sizeof(ListNode));
    ln->val = 0;
    ln->next = NULL;
    return ln;
}

void pushLinkedList(ListNode *l1, int val)
{
    while (l1->next != NULL)
    {
        l1++;
    }
    l1->next = createLinkedList();
    l1->val = val;
}

int getNumberLinkedList(ListNode *l1)
{
    ListNode *base = l1;
    int number = 0;
    int position = 1;
    while (l1->next != NULL)
    {
        l1++;
        position *= 10;
    }
    while (base != l1)
    {
        number += l1->val * position;
        position /= 10;
        l1--;
    }
    number += l1->val;
    return number;
}