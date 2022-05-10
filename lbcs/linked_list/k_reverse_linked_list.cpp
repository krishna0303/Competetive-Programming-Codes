#include <bits/stdc++.h>
using namespace std;

/*
Given a singly linked list and an integer K, reverses the nodes of the

list K at a time and returns modified linked list.

NOTE : The length of the list is divisible by K

Example :

Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,

You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

Try to solve the problem using constant extra space.
for better understanding watch apna college video
for iterative approach watch striver video
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *reverseList(ListNode *A, int B)
{
    ListNode *prev = NULL, *curr = A, *next;
    int count = 0;
    while (curr != NULL && count < B)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next != NULL)
    {
        A->next = reverseList(next, B);
    }
    return prev;
}
