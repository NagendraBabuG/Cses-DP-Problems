#include <bits/stdc++.h>
using namespace std;
int moneySum(int index, int target, vector<int> &coins, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        return target % coins[index] == 0 ? 1 : 0;
        if (target == 0)
            return 1;
        if (dp[index][target] != -1)
            return dp[index][target];
        int notPick = moneySum(index - 1, target, coins, dp);
        int pick = 0;
        if (coins[index] <= target)
            pick = moneySum(index - 1, target - coins[index], coins, dp);
        dp[index][target] = notPick + pick;
        if (dp[index][target] == 1)
            cout << target << endl;
        return dp[index][target];
    }
    int main()
    {
        int n;
        cin >> n;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int sum = 0;
        for (auto it : a)
            sum += it;
        int target = sum;
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        moneySum(n - 1, sum, a, dp);
        vector<int> res;
        for (int val = 1; val <= target; val++)
        {
            bool flag = false;
            for (int ind = 0; ind < n; ind++)
            {

                if (dp[ind][val] > 0)
                    flag = true;
            }
            if (flag)
                res.push_back(val);
        }
        cout << res.size() << endl;
        for (auto it : res)
        {
            cout << it << " ";
        }
        cout << endl;
        return 0;
    }