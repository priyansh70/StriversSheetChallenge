// Time Complexity - O(2nlogn)
// Space complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr

    // storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int cnt = 0;
    int right = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > (2LL * arr[right]))
        {
            right++;
        }
        cnt += (right - (mid + 1));
    }

    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    // Base Case
    int cnt = 0;
    if (low >= high)
    {
        return cnt;
    }

    // Find mid
    int mid = low + (high - low) / 2;

    // Call for Sorting from low to mid
    cnt += mergeSort(arr, low, mid);

    // Call for Sorting from mid+1 to high
    cnt += mergeSort(arr, mid + 1, high);

    // count pairs
    cnt += countPairs(arr, low, mid, high);

    // merge array
    merge(arr, low, mid, high);

    return cnt;
}

int reversePairs(vector<int> &nums)
{
    return mergeSort(nums, 0, nums.size() - 1);
}
