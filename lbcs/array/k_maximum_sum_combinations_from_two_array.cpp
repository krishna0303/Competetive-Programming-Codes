/*

Given two equally sized arrays (A, B) and N (size of both arrays).
A sum combination is made by adding one element from array A and another element of array B. Display the maximum K valid sum combinations from all the possible sum combinations.
Input :  A[] : {3, 2}
         B[] : {1, 4}
         K : 2 [Number of maximum sum
               combinations to be printed]
Output : 7    // (A : 3) + (B : 4)
         6    // (A : 2) + (B : 4)

Input :  A[] : {4, 2, 5, 1}
         B[] : {8, 0, 3, 5}
         K : 3
Output : 13   // (A : 5) + (B : 8)
         12   // (A : 4) + (B :  8)
         10   // (A : 2) + (B : 8)

Approach 1 (Naive Algorithm) :
We can use Brute force through all the possible combinations that can be made by taking one element from array A and another from array B and inserting them to a max heap. In a max heap maximum element is at the root node so whenever we pop from max heap we get the maximum element present in the heap. After inserting all the sum combinations we take out K elements from max heap and display it.
Below is the implementation of the above approach.
// A simple C++ program to find N maximum
// combinations from two arrays,
#include <bits/stdc++.h>
using namespace std;

// function to display first N maximum sum
// combinations
void KMaxCombinations(int A[], int B[],
                    int N, int K)
{
    // max heap.
    priority_queue<int> pq;

    // insert all the possible combinations
    // in max heap.
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            pq.push(A[i] + B[j]);

    // pop first N elements from max heap
    // and display them.
    int count = 0;
    while (count < K) {
        cout << pq.top() << endl;
        pq.pop();
        count++;
    }
}

// Driver Code.
int main()
{
    int A[] = { 4, 2, 5, 1 };
    int B[] = { 8, 0, 5, 3 };
    int N = sizeof(A) / sizeof(A[0]);
    int K = 3;

    // Function call
    KMaxCombinations(A, B, N, K);
    return 0;
}

Time Complexity: O(N2)

Approach 2 (Sorting, Max heap, Map) :
Instead of brute-forcing through all the possible sum combinations, we should find a way to limit our search space to possible candidate sum combinations.

Sort both arrays array A and array B.
Create a max heap i.e priority_queue in C++ to store the sum combinations along with the indices of elements from both arrays A and B which make up the sum. Heap is ordered by the sum.
Initialize the heap with the maximum possible sum combination i.e (A[N – 1] + B[N – 1] where N is the size of array) and with the indices of elements from both arrays (N – 1, N – 1). The tuple inside max heap will be (A[N-1] + B[N – 1], N – 1, N – 1). Heap is ordered by first value i.e sum of both elements.
Pop the heap to get the current largest sum and along with the indices of the element that make up the sum. Let the tuple be (sum, i, j).
Next insert (A[i – 1] + B[j], i – 1, j) and (A[i] + B[j – 1], i, j – 1) into the max heap but make sure that the pair of indices i.e (i – 1, j) and (i, j – 1) are not
already present in the max heap. To check this we can use set in C++.
Go back to 4 until K times.
*/

// An efficient C++ program to find top K elements
// from two arrays.
#include <bits/stdc++.h>
using namespace std;

// Function prints k maximum possible combinations
void KMaxCombinations(vector<int> &A,
                      vector<int> &B, int K)
{
    // sort both arrays A and B
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int N = A.size();

    // Max heap which contains tuple of the format
    // (sum, (i, j)) i and j are the indices
    // of the elements from array A
    // and array B which make up the sum.
    priority_queue<pair<int, pair<int, int>>> pq;

    // my_set is used to store the indices of
    // the pair(i, j) we use my_set to make sure
    // the indices doe not repeat inside max heap.
    set<pair<int, int>> my_set;

    // initialize the heap with the maximum sum
    // combination ie (A[N - 1] + B[N - 1])
    // and also push indices (N - 1, N - 1) along
    // with sum.
    pq.push(make_pair(A[N - 1] + B[N - 1],
                      make_pair(N - 1, N - 1)));

    my_set.insert(make_pair(N - 1, N - 1));

    // iterate upto K
    for (int count = 0; count < K; count++)
    {
        // tuple format (sum, (i, j)).
        pair<int, pair<int, int>> temp = pq.top();
        pq.pop();

        cout << temp.first << endl;

        int i = temp.second.first;
        int j = temp.second.second;

        int sum = A[i - 1] + B[j];

        // insert (A[i - 1] + B[j], (i - 1, j))
        // into max heap.
        pair<int, int> temp1 = make_pair(i - 1, j);

        // insert only if the pair (i - 1, j) is
        // not already present inside the map i.e.
        // no repeating pair should be present inside
        // the heap.
        if (my_set.find(temp1) == my_set.end())
        {
            pq.push(make_pair(sum, temp1));
            my_set.insert(temp1);
        }

        // insert (A[i] + B[j - 1], (i, j - 1))
        // into max heap.
        sum = A[i] + B[j - 1];
        temp1 = make_pair(i, j - 1);

        // insert only if the pair (i, j - 1)
        // is not present inside the heap.
        if (my_set.find(temp1) == my_set.end())
        {
            pq.push(make_pair(sum, temp1));
            my_set.insert(temp1);
        }
    }
}

// Driver Code.
int main()
{
    vector<int> A = {1, 4, 2, 3};
    vector<int> B = {2, 5, 1, 6};
    int K = 4;

    // Function call
    KMaxCombinations(A, B, K);
    return 0;
}
