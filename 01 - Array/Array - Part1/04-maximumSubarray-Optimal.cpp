// Time Complexity - O(n)
// Space Complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

// Kadane's Algorithm
int maxSubArray(vector<int> &nums)
{
    int maxiSum = nums[0];
    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        // Step1 -> add current element to sum
        sum += nums[i];

        // Step2 -> if sum is greater than maxisum
        // then update maximum Sum
        maxiSum = max(sum, maxiSum);

        // Step3 -> If Sum is less than 0 which means
        // it never get maximum sum so we will again set sum to 0
        sum = (sum < 0) ? 0 : sum;
    }
    return maxiSum;
}