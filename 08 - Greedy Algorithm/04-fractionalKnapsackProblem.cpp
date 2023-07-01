// Time Complexity - O(nlogn) +  O(n*m)
// Space complexity - O(1)
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    double r1 = (double)p1.second / p1.first;
    double r2 = (double)p2.second / p2.first;

    return r1 > r2;
}
double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    // Sort Items Accordingly to Unit Higher Value
    sort(items.begin(), items.end(), compare);

    double maxiValue = 0;
    //   w -= items[0].first;

    for (int i = 0; i < n; i++)
    {
        if (w >= items[i].first)
        {
            maxiValue += items[i].second;
            w -= items[i].first;
        }
        else
        {
            maxiValue = maxiValue + (items[i].second * ((double)w / items[i].first));
            break;
        }
    }
    return maxiValue;
}