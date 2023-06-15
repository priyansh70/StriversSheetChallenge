// Given the row number n. Print the n-th row of Pascal’s triangle.

// Time Complexity - O(n)
// Space Complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

void pascalTriangleRow(int n)
{
    // First ELement is Always 1
    long long element = 1;
    cout << element << " ";

    // Formula for nextElement = prevElement * (rowNumber - colIndex)/colIndex
    for (int i = 1; i < n; i++)
    {
        element = element * (n - i) / i;
        cout << element << " ";
    }
}

int main()
{
    int n = 6;
    cout << n << "th Row of Pascal Triangle is : ";
    pascalTriangleRow(n);

    return 0;
}