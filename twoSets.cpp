#include <bits/stdc++.h>
using namespace std;
int noWays(int ind, int n, int target, vector<vector<int>> &dp)
{
    if (target == 0)
        return 1;
    if (ind == 0)
        return target % (ind + 1) == 0;
    if (dp[ind][target] != -1)
        return dp[ind][target];
    int notPick = noWays(ind - 1, n, target, dp);
    int pick = 0;
    if ((ind + 1) <= target)
        pick = noWays(ind - 1, n, target - ind - 1, dp);
    return dp[ind][target] = pick + notPick;
}
int main()
{
    int sum = 0;
    int n;
    cin >> n;
    sum = ((n * (n + 1)) / 2);
    if (sum % 2 == 1)
        cout << "0\n";
    else
    {
        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        cout << noWays(n - 1, n, target, dp) << endl;
    }
}