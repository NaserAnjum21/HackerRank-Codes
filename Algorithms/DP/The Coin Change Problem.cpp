#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 2e5 + 5;
int t, a, b, c, d, n, m, k, p, q, x, y, ans;

LL coins[52];
LL dp[252][52];

LL Solve(int n, int i)
{
    if (i < 0 or n < 0)
        return 0;
    if (n == 0)
        return 1;

    if (dp[n][i] != -1)
        return dp[n][i];

    LL ret = Solve(n - coins[i], i) + Solve(n, i - 1);

    return dp[n][i] = ret;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    //freopen("input.txt", "r", stdin);

    memset(dp, -1, sizeof(dp));

    cin >> n >> m;

    for (int i = 0; i < m; i++)
        cin >> coins[i];

    cout << Solve(n, m - 1) << endl;

    return 0;
}
