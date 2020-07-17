#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 2e5 + 5;
const LL mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int n, k, x;

    cin >> n >> k >> x;

    LL dp[n + 1][2];
    memset(dp, 0, sizeof(dp));

    dp[1][0] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = (k - 1) * dp[i - 1][1] % mod;
        dp[i][1] = ((k - 2) * dp[i - 1][1] + dp[i - 1][0]) % mod;
    }

    LL ans = x == 1 ? dp[n][0] : dp[n][1];

    cout << ans << endl;

    return 0;
}
