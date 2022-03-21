// Problem Description

//     Given an array A of size N.You need to find the sum of Maximum and Minimum element in the given array.

//     NOTE : You should make minimum number of comparisons.

/*

METHOD 2 (Tournament Method)  best approach we can use linear search to find max and min in array
Divide the array into two parts and compare the maximums and minimums of the two parts to get the maximum and the minimum of the whole array.

Pair MaxMin(array, array_size)
   if array_size = 1
      return element as both max and min
   else if arry_size = 2
      one comparison to determine max and min
      return that pair
   else    /* array_size  > 2 */
//   recur for max and min of left half
//   recur for max and min of right half
//   one comparison determines true max of the two candidates
//   one comparison determines true min of the two candidates
//   return the pair of max and min

// C++ program of above implementation
#include <iostream>
using namespace std;

// structure is used to return
// two values from minMax()
struct Pair
{
    int min;
    int max;
};

struct Pair getMinMax(int arr[], int low,
                      int high)
{
    struct Pair minmax, mml, mmr;
    int mid;

    // If there is only one element
    if (low == high)
    {
        minmax.max = arr[low];
        minmax.min = arr[low];
        return minmax;
    }

    // If there are two elements
    if (high == low + 1)
    {
        if (arr[low] > arr[high])
        {
            minmax.max = arr[low];
            minmax.min = arr[high];
        }
        else
        {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        return minmax;
    }

    // If there are more than 2 elements
    mid = (low + high) / 2;
    mml = getMinMax(arr, low, mid);
    mmr = getMinMax(arr, mid + 1, high);

    // Compare minimums of two parts
    if (mml.min < mmr.min)
        minmax.min = mml.min;
    else
        minmax.min = mmr.min;

    // Compare maximums of two parts
    if (mml.max > mmr.max)
        minmax.max = mml.max;
    else
        minmax.max = mmr.max;

    return minmax;
}

// Driver code
int main()
{
    int arr[] = {1000, 11, 445,
                 1, 330, 3000};
    int arr_size = 6;

    struct Pair minmax = getMinMax(arr, 0,
                                   arr_size - 1);

    cout << minmax.max + minmax.min << endl;

    return 0;
}

// This code is contributed by nik_3112
