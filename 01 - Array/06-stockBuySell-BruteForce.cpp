// Time Complexity - O(n^2)
// Space Complexity - O(1)

#include <bits/stdc++.h> 
using namespace std;

int maximumProfit(vector<int> &prices){
    int profit = 0;
    for(int i=0;i<prices.size();i++){
        for(int j =i+1;j<prices.size();j++){
            if(prices[j] > prices[i])
                profit = max(profit,prices[j]-prices[i]);
        }
    }
    return profit;
}