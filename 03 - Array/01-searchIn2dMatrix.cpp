// Time Complexity - O(log(n*m))
// Space complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    // Getting row and column numbers
    int row = matrix.size();
    int col = matrix[0].size();

    // set variable start and end
    int start = 0; // point on first element
    int end = (row * col) - 1;

    while (start <= end)
    {
        // take a mid
        int mid = start + (end - start) / 2;

        // using mid to get element from the matrix
        // for row number - mid/col
        // for column number - mid%col
        int element = matrix[mid / col][mid % col];

        if (element == target)
            return true;
        else if (element > target)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return false;
}
