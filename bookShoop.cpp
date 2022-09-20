#include <bits/stdc++.h>
using namespace std;
int maxPages(int index, int target, vector<int> &prices, vector<int> &pages, vector<vector<int>> &dp)
{
    if (index == prices.size())
        return 0;
    if (target == 0)
        return 0;
    if (dp[index][target] != -1)
        return dp[index][target];
    int notPick = maxPages(index + 1, target, prices, pages, dp);
    int pick = INT_MIN;
    if (prices[index] <= target)
        pick = pages[index] + maxPages(index + 1, target - prices[index], prices, pages, dp);

    return dp[index][target] = max(notPick, pick);
}
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> prices(n, 0), pages(n, 0);
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int target = 0; target <= x; target++)
        {
            int notPick = dp[i + 1][target];

            int pick = INT_MIN;
            if (prices[i] <= target)
                pick = pages[i] + dp[i + 1][target - prices[i]];

            dp[i][target] = max(notPick, pick);
        }
    }
    cout << dp[0][x] << endl;

    // cout << maxPages(0, x, prices, pages, dp) << endl;

    return 0;
}