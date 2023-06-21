// Time Complexity - O(n^3)
// Space complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{ 
    // Sort the given array
    sort(nums.begin(), nums.end());

    // size of array
    int n = nums.size();

    // Declare answer
    vector<vector<int>> ans;

    // basically we have to find a,b,c and d
    // such that a+b+c+d = target
    for (int i = 0; i < n; i++)
    {

        // Remove Redundancy
        if (i > 0 && (nums[i] == nums[i - 1]))
            continue;

        // fix one element let's see
        int a = nums[i];

        // Three Sum Logic
        for (int j = i + 1; j < n; j++)
        {
            // Remove Redundancy
            if (j > i + 1 && (nums[j] == nums[j - 1]))
                continue;

            // Now Fix Second Element
            int b = nums[j];

            // Now apply Two Sum Approach
            int low = j + 1;
            int high = n - 1;

            while (low < high)
            {
                int c = nums[low];
                int d = nums[high];
                long long sum = (long long)a + b + c + d;

                if (sum == target)
                {
                    ans.push_back({a, b, c, d});
                    while (low < high && (nums[low] == nums[low + 1]))
                        low++;
                    while (low < high && (nums[high] == nums[high - 1]))
                        high--;
                    low++;
                    high--;
                }
                else if (sum < target)
                {
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }
    }
    return ans;
}