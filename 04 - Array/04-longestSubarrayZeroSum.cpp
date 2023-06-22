// Time Complexity - O(nlogn)
// Space complexity - O(n)

#include <bits/stdc++.h>
using namespace std;

int LongestSubsetWithZeroSum(vector<int> arr)
{
    map<int, int> mpp;
    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            maxLen = i + 1;
        }
        else
        {
            if (mpp[sum])
            {
                maxLen = max(maxLen, i - mpp[sum]);
            }
            else
            {
                mpp[sum] = i;
            }
        }
    }
    return maxLen;
}