// Time Complexity - O(N)
// Space complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int maxiOnes = 0;
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
            cnt++;
        else
            cnt = 0;
        maxiOnes = max(maxiOnes, cnt);
    }
    return maxiOnes;
}