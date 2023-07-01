// Time Complexity - O(nlogn) +  O(n*m)
// Space complexity - O(m)
#include <bits/stdc++.h>
using namespace std;
bool compare(vector<int> p1, vector<int> p2)
{
    if (p1[1] == p2[1])
        return p1[0] >= p2[0];
    return p1[1] > p2[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), compare);

    int maximumDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        maximumDeadline = max(maximumDeadline, jobs[i][0]);
    }

    int slots[maximumDeadline + 1];
    for (int i = 0; i <= maximumDeadline; i++)
        slots[i] = -1;

    int maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i][0]; j > 0; j--)
        {
            if (slots[j] == -1)
            {
                slots[j] = i + 1;
                maxProfit += jobs[i][1];
                break;
            }
        }
    }

    return maxProfit;
}
