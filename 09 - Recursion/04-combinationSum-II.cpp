// Time Complexity - O(2^n * k) where t is the target, k is the average length
// Space Complexity - O(k*x), k is the average length and x is the no. of combinations
#include <bits/stdc++.h>
using namespace std;
void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
  if (target == 0) {
    ans.push_back(ds);
    return;
  }
  for (int i = ind; i < arr.size(); i++) {
    if (i > ind && arr[i] == arr[i - 1]) continue;
    if (arr[i] > target) break;
    ds.push_back(arr[i]);
    findCombination(i + 1, target - arr[i], arr, ans, ds);
    ds.pop_back();
  }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	vector<vector<int>>ans;
	vector<int>ds;
	sort(arr.begin(),arr.end());
	findCombination(0,target,arr,ans,ds);
	return ans;
}
