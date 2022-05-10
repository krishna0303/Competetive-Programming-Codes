

#include <bits/stdc++.h>
using namespace std;

/*

Given n non-negative integers a1, a2, ..., an,

where each represents a point at coordinate (i, ai).

'n' vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).

Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Your program should return an integer which corresponds to the maximum area of water that can be contained ( Yes, we know maximum area instead of maximum volume sounds weird. But this is 2D plane we are working with for simplicity ).

Note: You may not slant the container.

Example :

Input : [1, 5, 4, 3]
Output : 6

Explanation : 5 and 3 are distance 2 apart. So size of the base = 2. Height of container = min(5, 3) = 3.
So total area = 3 * 2 = 6
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
