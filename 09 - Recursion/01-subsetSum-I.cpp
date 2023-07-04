// Time Complexity - O(2^t * k) where t is the target, k is the average length
// Space Complexity - O(k*x), k is the average length and x is the no. of combinations

#include <bits/stdc++.h>
using namespace std;

void help(int index, vector<int> arr, int n, vector<int> &ans, int sum)
{
    if (index == n)
    {
        ans.push_back(sum);
        return;
    }

    sum += arr[index];
    help(index + 1, arr, n, ans, sum);

    sum -= arr[index];
    help(index + 1, arr, n, ans, sum);
}
vector<int> subsetSum(vector<int> &num)
{
    int n = num.size();
    vector<int> ans;
    help(0, num, n, ans, 0);

    sort(ans.begin(), ans.end());
    return ans;
}