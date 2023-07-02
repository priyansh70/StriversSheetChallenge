// Time Complexity - O(N) + O(NlogN)
// Space Complexity - O(N)

#include <bits/stdc++.h>
using namespace std;
int maximumActivities(vector<int> &start, vector<int> &finish)
{
    vector<pair<int, int>> activity;
    int n = start.size();
    for (int i = 0; i < n; i++)
    {
        activity.push_back(make_pair(finish[i], start[i]));
    }

    sort(activity.begin(), activity.end());

    int cnt = 1;
    int limit = activity[0].first;

    for (int i = 1; i < n; i++)
    {
        if (limit <= activity[i].second)
        {
            cnt++;
            limit = activity[i].first;
        }
    }
    return cnt;
}