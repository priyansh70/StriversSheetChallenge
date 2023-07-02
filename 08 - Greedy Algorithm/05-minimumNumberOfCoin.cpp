// Time Complexity - O(amount)
// Space Complexity - O(1)

#include <bits/stdc++.h>
using namespace std;
int findMinimumCoins(int amount)
{
    int minimumCoins = 0;
    int coins[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};

    for (int i = 0; i < 9; i++)
    {
        while (amount >= coins[i])
        {
            amount -= coins[i];
            minimumCoins++;
        }
        if (!amount)
            break;
    }

    return minimumCoins;
}
#include <bits/stdc++.h>
int findMinimumCoins(int amount)
{
    int minimumCoins = 0;
    int coins[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};

    for (int i = 0; i < 9; i++)
    {
        while (amount >= coins[i])
        {
            amount -= coins[i];
            minimumCoins++;
        }
        if (!amount)
            break;
    }

    return minimumCoins;
}
#include <bits/stdc++.h>
int findMinimumCoins(int amount)
{
    int minimumCoins = 0;
    int coins[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};

    for (int i = 0; i < 9; i++)
    {
        while (amount >= coins[i])
        {
            amount -= coins[i];
            minimumCoins++;
        }
        if (!amount)
            break;
    }

    return minimumCoins;
}
