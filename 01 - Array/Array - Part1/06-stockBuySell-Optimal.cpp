// Time Complexity - O(n^2)
// Space Complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    // set variable for track maximum profit and minimum price
    int maximumProfit = 0;
    int minimumPrice = INT_MAX;

    for (int i = 0; i < prices.size(); i++)
    {
        // Check if current element is minimum price
        // if yes than update it
        minimumPrice = min(minimumPrice, prices[i]);

        // maximum profit is difference between
        // minimum price and current day price
        // if it is greater than current profit then update it
        maximumProfit = max(maximumProfit, prices[i] - minimumPrice);
    }
    return maximumProfit;
}