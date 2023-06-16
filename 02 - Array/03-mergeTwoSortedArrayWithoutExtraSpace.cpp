// Time Complexity - O(min(n,m)) + O(nlogn) + O(mlogm)
// Space Complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int index1 = m - 1;
    int index2 = 0;

    while (index1 >= 0 && index2 < n)
    {
        // Compare Last Element of 1st array to first element of 2nd array
        if (nums1[index1] > nums2[index2])
        {
            swap(nums1[m++], nums2[index2]);
            index1--;
            index2++;
        }

        // That means both arry have thier element in sorted or unsorted manner 
        else
        {
            break;
        }
    }
    if (index2 != n)
    {
        while (index2 < n)
        {
            nums1[m++] = nums2[index2++];
        }
    }
    sort(nums1.begin(), nums1.end());
}
