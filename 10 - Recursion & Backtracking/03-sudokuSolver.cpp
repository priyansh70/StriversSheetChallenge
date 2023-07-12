// Time Complexity: O(9(n ^ 2)), in the worst case,
//  for each cell in the n2 board, we have 9 possible numbers.

// Space Complexity: O(1), since we are refilling the given board itself,
//  there is no extra space required, so constant space complexity.

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<char>> &board, int val)
{
    for (int i = 0; i < 9; i++)
    {
        // Check row
        if (board[row][i] == val)
            return false;

        // check col
        if (board[i][col] == val)
            return false;

        // check 3*3 grid
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
            return false;
    }
    return true;
}
bool help(vector<vector<char>> &board)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            // if empty cell
            if (board[row][col] == '.')
            {
                // try to put number in this cell
                for (char i = '1'; i <= '9'; i++)
                {
                    if (isSafe(row, col, board, i))
                    {
                        board[row][col] = i;
                        if (help(board))
                        {
                            return true;
                        }
                        else
                        {
                            board[row][col] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    help(board);
}