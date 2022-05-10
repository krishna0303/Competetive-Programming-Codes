

// C++ code for Maximum size square
// sub-matrix with all 1s
#include <bits/stdc++.h>
#define bool int
#define R 6
#define C 5
using namespace std;

void printMaxSubSquare(bool M[R][C])
{
    int i, j;
    int S[R][C];
    int max_of_s, max_i, max_j;

    /* Set first column of S[][]*/
    for (i = 0; i < R; i++)
        S[i][0] = M[i][0];

    /* Set first row of S[][]*/
    for (j = 0; j < C; j++)
        S[0][j] = M[0][j];

    /* Construct other entries of S[][]*/
    for (i = 1; i < R; i++)
    {
        for (j = 1; j < C; j++)
        {
            if (M[i][j] == 1)
                S[i][j] = min({S[i][j - 1], S[i - 1][j],
                               S[i - 1][j - 1]}) +
                          1; // better of using min in case of arguments more than 2
            else
                S[i][j] = 0;
        }
    }

    /* Find the maximum entry, and indexes of maximum entry
        in S[][] */
    max_of_s = S[0][0];
    max_i = 0;
    max_j = 0;
    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
        {
            if (max_of_s < S[i][j])
            {
                max_of_s = S[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    cout << "Maximum size sub-matrix is: \n";
    for (i = max_i; i > max_i - max_of_s; i--)
    {
        for (j = max_j; j > max_j - max_of_s; j--)
        {
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }
}

/* Driver code */
int main()
{
    bool M[R][C] = {{0, 1, 1, 0, 1},
                    {1, 1, 0, 1, 0},
                    {0, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0}};

    printMaxSubSquare(M);
}

// This code is contributed by rathbhupendra
/*

Time Complexity: O(m*n) where m is the number of rows and n is the number of columns in the given matrix.
Auxiliary Space: O(m*n) where m is the number of rows and n is the number of columns in the given matrix.
*/

// C++ code for Maximum size square
// sub-matrix with all 1s
// (space optimized solution)

#define R 6
#define C 5

void printMaxSubSquare(bool M[R][C])
{
    int S[2][C], Max = 0;

    // set all elements of S to 0 first
    memset(S, 0, sizeof(S));

    // Construct the entries
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {

            // Compute the entrie at the current position
            int Entrie = M[i][j];
            if (Entrie)
                if (j)
                    Entrie = 1 + min(S[1][j - 1], min(S[0][j - 1], S[1][j]));

            // Save the last entrie and add the new one
            S[0][j] = S[1][j];
            S[1][j] = Entrie;

            // Keep track of the max square length
            Max = max(Max, Entrie);
        }

    // Print the square
    cout << "Maximum size sub-matrix is: \n";
    for (int i = 0; i < Max; i++, cout << '\n')
        for (int j = 0; j < Max; j++)
            cout << "1 ";
}

// Driver code
int main()
{
    bool M[R][C] = {{0, 1, 1, 0, 1},
                    {1, 1, 0, 1, 0},
                    {0, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0}};

    printMaxSubSquare(M);

    return 0;

    // This code is contributed
    // by Gatea David
}

/*
Time Complexity: O(m*n) where m is the number of rows and n is the number of columns in the given matrix.
 Auxiliary space: O(n) where n is the number of columns in the given matrix.

*/