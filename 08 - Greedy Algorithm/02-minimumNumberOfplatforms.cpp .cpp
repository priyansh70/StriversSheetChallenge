// Time Complexity - O(2N) + O(2NlogN)
// Space Complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n)
{
    vector<pair<int, int>> minPlatforms;
    int cnt = 0;
    sort(at, at + n);
    sort(dt, dt + n);

    int platformNeeded = 1;
    int maxiPlatform = 1;

    int i = 1;
    int j = 0;

    while (i < n && j < n)
    {
        // current train is come on platform but already train present
        if (at[i] <= dt[j])
        {
            platformNeeded++;
            i++;
        }
        // Platform Free
        else
        {
            platformNeeded--;
            j++;
        }

        maxiPlatform = max(maxiPlatform, platformNeeded);
    }

    return maxiPlatform;
}