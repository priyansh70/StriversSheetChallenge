// Time Complexity - O(N^2)
// Space complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    // Sort the array
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    // a+b+c = 0
    for (int i = 0; i < nums.size() - 2; i++)
    {
        // fix a
        int a = nums[i];

        // Now making a+b+c = 0
        // we fix a
        // so b+c should be -a

        if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
        {
            // Two Sum approach
            int low = i + 1;
            int high = nums.size() - 1;
            int target = 0 - a;
            while (low < high)
            {
                int b = nums[low];
                int c = nums[high];
                int sum = b + c;
                if (sum == target)
                {
                    // we found a b and c : a+b+c = 0
                    ans.push_back({a, b, c});

                    // Remove Redundancy of elements
                    while (low < high && nums[low] == nums[low + 1])
                        low++;
                    while (low < high && nums[high] == nums[high - 1])
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