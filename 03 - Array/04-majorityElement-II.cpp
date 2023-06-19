// Time Complexity - O(n)
// Space complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    vector<int> ans;
    int n = nums.size();

    // Create 4 Variables Used for Moore's Algorithm
    // cnt1 & cnt2 –  for tracking the counts of elements
    // el1 & el2 – for storing the majority of elements.
    int count1 = 0;
    int count2 = 0;
    int element1 = INT_MIN;
    int element2 = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (count1 == 0 && nums[i] != element2)
        {
            element1 = nums[i];
            count1++;
        }
        else if (count2 == 0 && nums[i] != element1)
        {
            element2 = nums[i];
            count2++;
        }
        else if (element1 == nums[i])
        {
            count1++;
        }
        else if (element2 == nums[i])
        {
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    count1 = 0;
    count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (element1 == nums[i])
            count1++;
        if (element2 == nums[i])
            count2++;
    }

    if (count1 > n / 3)
        ans.push_back(element1);
    if (count2 > n / 3)
        ans.push_back(element2);

    return ans;
}