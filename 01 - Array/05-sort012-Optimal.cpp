// Time Complexity - O(N)
// Space Complexity - O(1)

#include <bits/stdc++.h>
using namespace std;
void sort012(int *arr, int n)
{
    // set variables
    // low for 0
    // mid for 1
    // high for 2
    int low = 0;
    int mid = 0;
    int high = n - 1;

    // Run loop until mid <= high [1<2]
    while (mid <= high)
    {
        // if mid element is 0 then swap low and mid element and increment both
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        // if mid element is 2 that means is belongs to high group
        // swap high element and mid element and high--
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
        // mid element is 1 so increment mid++
        else
        {
            mid++;
        }
    }
}