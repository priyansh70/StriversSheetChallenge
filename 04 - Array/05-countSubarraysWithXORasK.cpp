// Time Complexity - O(nlogn)
// Space complexity - O(n)

#include <bits/stdc++.h>
using namespace std;

int subarraysXor(vector<int> &arr, int k)
{
    int n = arr.size();
    int xr = 0;
    int cnt = 0;
    map<int, int> mpp;

    mpp[xr]++;

    for (int i = 0; i < n; i++)
    {
        // prefix XOR till index i:
        xr ^= arr[i];

        // Check which xor is need - By formula: x = xr^k:
        int x = xr ^ k;

        // add the occurrence of xr^k
        // to the count:
        cnt += mpp[x];

        // Insert the prefix xor till index i
        // into the map:
        mpp[xr]++;
    }
    return cnt;
}