#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int coinsCombo(int index, vector<int> &coins, int n, int target, vector<vector<int>> &dp)
{
    if (target == 0)
        return 1;
    if (index == (n - 1))
        return target % coins[index] == 0;
    if (dp[index][target] != -1)
        return dp[index][target];
    int notPick = coinsCombo(index + 1, coins, n, target, dp);
    int pick = 0;
    if (coins[index] <= target)
        pick = coinsCombo(index, coins, n, target - coins[index], dp);
    return dp[index][target] = pick + notPick;
}

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> coins;
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        coins.push_back(t);
    }

    for (int ind = 0; ind < n; ind++)
        dp[ind][0] = 1;
    for (int sum = 0; sum <= target; sum++)
    {
        if (sum % coins[n - 1] == 0)
            dp[n - 1][sum] = 1;
    }
    for (int ind = n - 2; ind >= 0; ind--)
    {
        for (int sum = 0; sum <= target; sum++)
        {
            int notPick = dp[ind + 1][sum];
            int pick = 0;
            if (coins[ind] <= sum)
                pick = dp[ind][sum - coins[ind]];

            dp[ind][sum] = (pick + notPick) % mod;
        }
    }

    cout << dp[0][target] << endl;

    // cout << coinsCombo(0, coins, n, target, dp) << endl;
}