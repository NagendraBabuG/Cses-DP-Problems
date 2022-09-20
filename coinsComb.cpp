#include <bits/stdc++.h>

using namespace std;
long long mod = 1e9 + 7;
vector<long long> dp(1e6 + 1, -1);
long long noCombinations(int sum)
{
    if (sum == 0)
        return 1;
    if (sum < 0)
        return 0;
    long long noWays = 0;
    if (dp[sum] != -1)
        return dp[sum];
    for (int i = 1; i <= 6; i++)
    {
        if (i <= sum)
            noWays = (noWays + noCombinations(sum - i)) % mod;
    }
    return dp[sum] = noWays % mod;
}
int main()
{
    int n;
    cin >> n;
    //  vector<int> a{1, 2, 3, 4, 5, 6};
    vector<long long> res(n + 1, 0);
    res[0] = 1;
    res[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int chance = 1; chance <= 6; chance++)
        {
            if (chance <= i)
            {
                res[i] = (res[i] + res[i - chance]) % mod;
            }
        }
    }

    cout << res[n] % mod << endl;
    return 0;
}
/*
                5
            5 3 2 1 0
    4 3 2 1 0 2 1 0 0
    3 2 1 0 2 1 0 0 1 0 1 0
    2 1 0 1 0 0 1 0 0
    1 0 0 0 0
    0







*/