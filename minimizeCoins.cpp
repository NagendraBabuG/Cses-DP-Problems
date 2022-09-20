#include <bits/stdc++.h>
using namespace std;

int minCoins(int index, vector<int> &coins, int n, int target, vector<vector<int>> &dp)
{
    if (index == (n - 1))
    {
        if (target % coins[index] == 0)
            return target / coins[index];
        return 1e7;
    }
    if (target == 0)
        return 0;
    int notPick = minCoins(index + 1, coins, n, target, dp);
    int pick = 1e7;
    if (coins[index] <= target)
        pick = 1 + minCoins(index, coins, n, target - coins[index], dp);
    return dp[index][target] = min(pick, notPick);
}

int main()
{

    int n, target;
    vector<int> coins;
    cin >> n >> target;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        coins.push_back(t);
    }
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    for (int money = 0; money <= target; money++)
    {
        if (money % coins[n - 1] == 0)
            dp[n - 1][money] = money / coins[n - 1];
        else
            dp[n - 1][money] = 1e7;
    }
    for (int ind = n - 2; ind >= 0; ind--)
    {
        for (int sum = 0; sum <= target; sum++)
        {
            int notPick = dp[ind + 1][sum];
            int pick = 1e7;
            if (coins[ind] <= sum)
                pick = 1 + dp[ind][sum - coins[ind]];
            dp[ind][sum] = min(notPick, pick);
        }
    }

    int ans = dp[0][target];
    if (ans >= 1e7)
        ans = -1;
    cout << ans << endl;
    return 0;
}