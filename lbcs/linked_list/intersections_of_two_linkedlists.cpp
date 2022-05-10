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
for better understanding of this approach watch satriver video for more approach also
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *getIntersectionNode(ListNode *A, ListNode *B)
{
    if (A == NULL || B == NULL)
        return NULL;
    ListNode *s = A;
    ListNode *t = B;
    while (s != t)
    {
        if (s == NULL)
        {
            s = B;
        }
        else
            s = s->next;
        if (t == NULL)
            t = A;
        else
            t = t->next;
    }
    return s;
}
