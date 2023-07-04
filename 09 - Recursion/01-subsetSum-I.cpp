// Time Complexity -O(2^n)+O(2^n log(2^n)).
//  Each index has two ways. You can either pick it up or not pick it.
//  So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n)).

// Space Complexity - O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n.

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