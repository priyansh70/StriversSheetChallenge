// Brute Force Approach
// Time Complexity - O(N*M) = O(N^2)
// Space Complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int col0 = 1;

        // Step1 - traverse matrix and see where 0 is available mark 1st(row & col) - 0
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    // Make i'th Row zero
                    matrix[i][0] = 0;

                    // Make i'th column zero
                    if (j != 0)
                    {
                        matrix[0][j] = 0;
                    }
                    else
                    {
                        col0 = 0;
                    }
                }
            }
        }

        // Step2 - Mark with 0 from (1,1) to (n-1, m-1):
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step3 - Mark the 1st col
        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[0][j] = 0;
            }
        }

        // Step4 - Mark the 1st Row
        if (col0 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};
