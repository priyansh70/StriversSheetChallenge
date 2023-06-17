// Time Complexity - O(n)
// Space Complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    // sum of n natural number and sum of n natural number's sqaure
    long long sumOfN = (n * (n + 1)) / 2;
    long long sumSquareOfN = (n * (n + 1) * (2 * n + 1)) / 6;

    // sum of array element and sum of array element's sqaure
    long long sumOfElement = 0;
    long long sumSquareofElement = 0;
    for (int i = 0; i < n; i++)
    {
        sumOfElement += arr[i];
        sumSquareofElement += ((long long)arr[i] * (long long)arr[i]);
    }

    // x-y
    long long xMinusY = sumOfElement - sumOfN;

    // x2 - y2 = (x+y)(x-y) => x+y = val/x-y
    long long xPlusY = (sumSquareofElement - sumSquareOfN) / xMinusY;

    long long repeate = (xMinusY + xPlusY) / 2;
    long long missing = repeate - xMinusY;

    return make_pair((int)missing, (int)repeate);
}
