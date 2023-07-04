// Time Complexity - O(2^t * k) where t is the target, k is the average length
// Space Complexity - O(k*x), k is the average length and x is the no. of combinations

#include <bits/stdc++.h>
using namespace std;

void help(int index, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &ds, int target)
{
    // Base Case
    if (index == candidates.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }

    // Pick The Current Element
    if (target - candidates[index] >= 0)
    {
        ds.push_back(candidates[index]);
        help(index, candidates, ans, ds, target - candidates[index]);
        ds.pop_back();
    }

    // Not Pick
    help(index + 1, candidates, ans, ds, target);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;

    help(0, candidates, ans, ds, target);
    return ans;
}