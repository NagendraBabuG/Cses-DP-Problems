#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> dp(1e6 + 1, vector<int>(10, -1));
vector<int> res(1e6 + 1, -1);
int solve(int n)
{
    if (n == 0)
        return 0;
    int tmp = n;
    if (res[n] != -1)
        return res[n];
    int mini = INT_MAX;
    while (tmp != 0)
    {
        int digit = tmp % 10;
        if (digit != 0)
            mini = min(mini, 1 + solve(n - digit));
        tmp = tmp / 10;
    }
    return res[n] = mini;
}

int main()
{
    int n;
    cin >> n;
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int tmp = i;
        int mini = INT_MAX;
        while (tmp != 0)
        {
            int digit = tmp % 10;
            if (digit != 0 && i - digit >= 0)
                mini = min(mini, 1 + ans[i - digit]);
            tmp /= 10;
        }
        ans[i] = mini;
    }
    cout << ans[n] << endl;

    return 0;
}