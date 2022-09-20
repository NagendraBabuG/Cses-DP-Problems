#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
// int nocombinations(vector<int> &coins, int target, vector<int> &res)
// {
//     if (target == 0)
//         return 1;
//     if (target < 0)
//         return 0;
//     if (res[target] != -1)
//         return res[target];
//     int noWays = 0;
//     for (int ind = 0; ind < coins.size(); ind++)
//     {
//         if (target >= coins[ind])
//             noWays = (noWays + nocombinations(coins, target - coins[ind], res)) % mod;
//     }
//     return res[target] = noWays % mod;
// }
int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    // vector<int> res(target + 1, 0);
    int res[target + 1];
    res[0] = 1;
    for (int sum = 1; sum <= target; sum++)
    {
        res[sum] = 0;
        for (auto it : coins)
        {
            if (it <= sum)
                res[sum] = (res[sum] + res[sum - it]) % mod;
        }
    }
    cout << res[target] << endl;
    // cout << nocombinations(coins, target, res) << endl;
    return 0;
}