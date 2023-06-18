// Time Complexity - O(logn))
// Space complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n)
{
    double power = 1.0;
    long long nn = n;
    nn = (nn < 0) ? (-1 * nn) : nn;

    while (nn)
    {
        //   if power is odd then -> ans * x^nn-1
        if (nn & 1)
        {
            power = power * x;
            nn--;
        }
        // if power is even -> x = x* x and nn/2
        else
        {
            x = x * x;
            nn /= 2;
        }
    }
    if (n < 0)
        return ((double)1.0 / (double)power);
    return power;
}