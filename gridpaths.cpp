#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int gridPaths(vector<vector<char>> &grid, int i, int j, int n, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0 || i >= n || j >= n)
        return 0;
    if (i == 0 && j == 0)
        return 1;
    if (grid[i][j] == '*')
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int paths = 0;
    if (i > 0)
        paths = (gridPaths(grid, i - 1, j, n, dp) + paths) % mod;
    if (j > 0)
        paths = (gridPaths(grid, i, j - 1, n, dp) + paths) % mod;
    return dp[i][j] = paths;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<char>> graph(n, vector<char>(n, '.'));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));

    dp[0][0] = 1;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {

            if (graph[row][col] == '*')
                dp[row][col] = 0;
            else if (row == 0 && col == 0)
                dp[row][col] = 1;
            else
            {
                int noPaths = 0;
                if (row > 0)
                    noPaths = (noPaths + dp[row - 1][col]) % mod;
                if (col > 0)
                    noPaths = (noPaths + dp[row][col - 1]) % mod;
                dp[row][col] = noPaths % mod;
            }
        }
    }
    cout << dp[n - 1][n - 1] << endl;
    // cout
    //     << gridPaths(graph, n - 1, n - 1, n, dp) << endl;

    return 0;
}