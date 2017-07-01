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
    ListNode *l3 = NULL;
    int rest = 0;
    int val;
    while (l1 != NULL && l2 != NULL)
    {
        val = rest + l1->val + l2->val;
        rest = val / 10;
        val = val % 10;
        pushLinkedList(&l3, val);
        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1 != NULL)
    {
        val = rest + l1->val;
        rest = val / 10;
        val = val % 10;
        pushLinkedList(&l3, val);
        l1 = l1->next;
    }

    while (l2 != NULL)
    {
        val = rest + l2->val;
        rest = val / 10;
        val = val % 10;
        pushLinkedList(&l3, val);
        l2 = l2->next;
    }

    return l3;
}

ListNode *createLinkedNode(int value)
{
    ListNode *ln = (ListNode *)malloc(sizeof(ListNode));
    ln->val = value;
    ln->next = NULL;
    return ln;
}

void pushLinkedList(ListNode **l1, int val)
{
    ListNode **p;
    ListNode *next;
    p = l1;
    //Check empty lis
    if (*p == NULL)
    {
        *p = createLinkedNode(val);
    }
    else
    {
        next = (*p);
        while (next->next != NULL)
        {
            next = next->next;
        }
        next->next = createLinkedNode(val);
    }
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