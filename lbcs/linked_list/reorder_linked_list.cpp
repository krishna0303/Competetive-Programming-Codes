#include <bits/stdc++.h>
using namespace std;

/*
Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,
reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
You must do this in-place without altering the nodes’ values.

For example,

Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *reverse(ListNode *head)
{
    ListNode *temp = head, *prev = NULL, *ptr;

    while (temp->next != NULL)
    {
        // cout<<ptr->val<<endl;
        ptr = temp->next;
        temp->next = prev;
        prev = temp;
        temp = ptr;
    }
    temp->next = prev;
    return temp;
}
ListNode *reorderList(ListNode *A)
{
    if (A == NULL || A->next == NULL || A->next->next == NULL)
    {
        return A;
    }
    ListNode *temp = A, *head, *ptr;
    ListNode *slow = A, *fast = A;
    int n = 0;
    while (temp != NULL)
    {
        n += 1;
        temp = temp->next;
    }
    if (n % 2 == 0)
    {
        n = n / 2;
    }
    else
    {
        n = n / 2 + 1;
    }
    temp = A;
    int count = 1;
    while (slow != NULL)
    {
        if (count == n)
        {
            break;
        }
        count += 1;
        slow = slow->next;
        // cout<<fast->val<<endl;
    }

    ListNode *newNode;
    // slow->next=NULL;
    // cout<<slow->next->val<<endl;

    slow->next = reverse(slow->next);
    // cout<<slow->next->val<<endl;
    newNode = slow->next;
    slow->next = NULL;
    // cout<<newNode->val<<endl;
    temp = A;
    ListNode *prev = A;
    while (temp != NULL && newNode != NULL)
    {
        // cout<<temp->val<<" "<<newNode->val<<endl;
        prev = temp;
        ptr = temp->next;
        temp->next = newNode;
        head = newNode->next;
        temp->next->next = ptr;
        newNode = head;
        temp = ptr;
    }

    return A;
}
