#include <bits/stdc++.h>
using namespace std;

void help(int i, int j, int n, vector<vector<int>> &matrix, const string &path, vector<string> &ans, vector<vector<int>> &visited, int *di, int *dj)
{
    // Base Case
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(path);
        return;
    }

    string dir = "DLRU";

    for (int ind = 0; ind < 4; ind++)
    {
        int x = i + di[ind];
        int y = j + dj[ind];

        // Conditions
        if (x >= 0 && y >= 0 && x < n && y < n && !visited[x][y] && matrix[x][y])
        {
            visited[i][j] = 1;
            help(x, y, n, matrix, path + dir[ind], ans, visited, di, dj);
            visited[i][j] = 0;
        }
    }
}
vector<string> findPath(vector<vector<int>> matrix, int n)
{
    string path = "";
    vector<string> ans;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    int di[] = {1, 0, 0, -1};
    int dj[] = {0, -1, 1, 0};
    help(0, 0, n, matrix, path, ans, visited, di, dj);
    return ans;
}