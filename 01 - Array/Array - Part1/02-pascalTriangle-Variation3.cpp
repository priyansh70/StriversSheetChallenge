// Given the number of rows n. Print the first n rows of Pascal’s triangle.

// Time Complexity - O(n^2)
// Space Complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

void pascalTriangleRow(int row)
{
    // First ELement is Always 1
    long long element = 1;
    cout << element << " ";

    // Formula for nextElement = prevElement * (rowNumber - colIndex)/colIndex
    for (int col = 1; col < row; col++)
    {
        element = element * (row - col) / col;
        cout << element << " ";
    }
    cout<<"\n";
}

void pascalTriangle(int n){
    for(int i=1; i <= n; i++)
    {
        // Generate Row 
        pascalTriangleRow(i);
    }
}

int main()
{
    int n = 6;
    cout <<"Pascal Triangle is : \n";
    pascalTriangle(n);

    return 0;
}