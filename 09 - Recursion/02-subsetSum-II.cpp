// Time Complexity = O(2^n * k)
// Space Complexity = O(2^n * k) + O(n)[Auxiliary Space]

#include <bits/stdc++.h>
using namespace std;
void help(int index, vector<int> arr, vector<vector<int>> &ans,
          vector<int> &ds) {
    ans.push_back(ds);

  for (int i = index; i <arr.size(); i++) {
    if (i != index && arr[i] == arr[i - 1]) {
      continue;
    }
    ds.push_back(arr[i]);
    help(i + 1, arr, ans, ds);
    ds.pop_back();
  }
}

  vector<vector<int>> uniqueSubsets(int n, vector<int> &arr) {
    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(), arr.end());
    help(0, arr, ans, ds);
    return ans;
  }