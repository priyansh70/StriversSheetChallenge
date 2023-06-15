// Brute Force Approach 
// Time Complexity - O(N*M*(N+M)) = O(N^3) 
// Space Complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void setZero(int i, int j, vector<vector<int>> &matrix, int n, int m)
    {
        // Set Row Zero
        for (int index = 0; index < m; index++)
        {
            if (matrix[i][index] != 0)
            {
                matrix[i][index] = -1;
            }
        }
        // Set Column Zero
        for (int index = 0; index < n; index++)
        {
            if (matrix[index][j] != 0)
            {
                matrix[index][j] = -1;
            }
        }
    }

public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // Check matrix element is 0 or not
                if (matrix[i][j] == 0)
                {
                    setZero(i, j, matrix, n, m);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
