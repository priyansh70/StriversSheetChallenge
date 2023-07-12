// Time Complexity: Exponential in nature,
// since we are trying out all ways. To be precise it goes as
// O(N!  N) nearly.

// Space Complexity: O(N)

#include <bits/stdc++.h>
using namespace std;
void help(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &rowCheck, vector<int> &ld, vector<int> &ud, int n)
{
    // Base Caser
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (!rowCheck[row] && !ud[row + col] && !ld[n - 1 + col - row])
        {
            rowCheck[row] = 1;
            ud[row + col] = 1;
            ld[n - 1 + col - row] = 1;
            board[row][col] = 'Q';
            help(col + 1, board, ans, rowCheck, ld, ud, n);
            rowCheck[row] = 0;
            ud[row + col] = 0;
            ld[n - 1 + col - row] = 0;
            board[row][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));

    vector<int> leftrow(n, 0);
    vector<int> upperDiagonal(2 * n - 1, 0);
    vector<int> lowerDiagonal(2 * n - 1, 0);

    help(0, board, ans, leftrow, lowerDiagonal, upperDiagonal, n);
    return ans;
}