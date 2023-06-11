// Brute Force Approach
// Time Complexity - O((N*M*)*2) 
// Space Complexity - O(N+M)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        // Create Array or Row and Column
        vector<int> row(n, 0);
        vector<int> col(m, 0);

        // Find Zero Place
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // Set Zero All the Col and Row which have to set
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (col[j] || row[i])
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};