// Time Complexity - O(n)
// Space Complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // #1 - Sort the Given Intervals
    sort(intervals.begin(), intervals.end());

    // #2 - Store 1st Element in the mergeIntervals(ans)
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);

    // #3 - Traverse Entire Intervals
    for (int i = 1; i < intervals.size(); i++)
    {
        // check interval ending is greater than
        // next interval starting that mean overlapping
        if (ans.back()[1] >= intervals[i][0])
        {
            ans.back()[1] = max(intervals[i][1], ans.back()[1]);
        }
        else
        {
            ans.push_back(intervals[i]);
        }
    }
    return ans;
}
