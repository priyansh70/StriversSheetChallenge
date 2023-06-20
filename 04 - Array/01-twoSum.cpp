// Time Complexity - O(nlogn)
// Space complexity - O(n)

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    // step1 - create map which is store number and their index
    map<int, int> mapping;

    // step2 - traverse nums array and check whether the (target - nums[i]) is exist in map is          or not if exist then add it into your answer and return
    for (int i = 0; i < nums.size(); i++)
    {
        if (mapping.find(target - nums[i]) != mapping.end())
        {
            return {mapping[target - nums[i]], i};
        }

        // step3 - if not exist then store it in you map
        mapping[nums[i]] = i;
    }
    return {};
}
