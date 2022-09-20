#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> dp(n, 1);
    int res = 1;
    for (int ind = 1; ind < n; ind++)
    {
        int maxi = 0;
        for (int j = ind - 1; j >= 0; j--)
        {
            if (a[ind] > a[j] && maxi < dp[j])
                maxi = dp[j];
        }

        dp[ind] = 1 + maxi;
        // cout << dp[ind] << endl;
        res = max(dp[ind], res);
    }
    cout << res << endl;

    return 0;
}