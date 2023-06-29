// Time Complexity - O(N)
// Space complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &arr)
{
    int trapWater = 0;
    int leftMax = 0;
    int rightMax = 0;
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        if (arr[left] <= arr[right])
        {
            if (arr[left] >= leftMax)
                leftMax = arr[left];
            else
            {
                trapWater += (leftMax - arr[left]);
            }
            left++;
        }
        else
        {
            if (arr[right] >= rightMax)
                rightMax = arr[right];
            else
            {
                trapWater += (rightMax - arr[right]);
            }
            right--;
        }
    }

    return trapWater;
}