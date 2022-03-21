/*

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:

Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:

Given m, n satisfy the following condition:

1 ≤ m ≤ n ≤ length of list.

Note 2:

Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// revision daily basis

ListNode *reverseBetween(ListNode *A, int B, int C)
{
    ListNode *temp = A, *current, *temp1, *prev, *prev1, *next, *prev2, *header;
    prev1 = A;
    header = A;
    current = NULL;
    if (A->next == NULL)
    {
        return A;
    }

    int i = 1;
    while (temp != NULL)
    {
        if (i == B)
        {
            prev = prev1;
            temp1 = temp;
            int count = 0;
            while (i >= B && i <= C && temp1 != NULL)
            {
                // prev2=prev;
                // temp1=prev->next;
                next = temp1->next;
                if (count == 0)
                {
                    temp1->next = NULL;
                    count = 1;
                }
                else
                {
                    temp1->next = prev;
                }

                prev = temp1;
                temp1 = next;

                i++;
            }
            if (B == 1)
            {
                header = prev;
                prev1->next = temp1;
            }
            else
            {
                prev1->next = prev;
                temp->next = temp1;
            }

            break;
        }
        else
        {
            prev1 = temp;
            temp = temp->next;
        }
        i++;
    }
    return header;
}
