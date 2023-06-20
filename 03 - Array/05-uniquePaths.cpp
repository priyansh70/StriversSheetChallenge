// Time Complexity - O(n-1) or (m-1)
// Space complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n)
{
    // nCr Solution
    int N = n + m - 2;
    int r = m - 1;
    double res = 1;

    for (int i = 1; i <= r; i++)
        res = res * (N - r + i) / i;
    return (int)res;
}