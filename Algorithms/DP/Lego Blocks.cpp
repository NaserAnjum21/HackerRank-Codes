#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 1e3 + 5;
const int mod = 1e9 + 7;
int t, n, m;
LL dp[N], p[N], good[N];

LL binpow(LL x, LL p)
{
    LL ret = 1;
    while (p > 0)
    {
        if (p & 1)
            ret = (ret * x) % mod;
        x = (x * x) % mod;
        p >>= 1;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        memset(good, 0, sizeof(good));
        memset(p, 0, sizeof(p));

        dp[0] = dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;

        for (int i = 4; i <= m; i++)
            dp[i] = (dp[i - 1] % mod + dp[i - 2] % mod + dp[i - 3] % mod + dp[i - 4] % mod) % mod;

        for (int i = 1; i <= m; i++)
            p[i] = binpow(dp[i], n);

        good[1] = 1;
        for (int i = 2; i <= m; i++)
        {
            good[i] = p[i];
            for (int j = 1; j < i; j++)
                good[i] = (good[i] % mod - ( (good[j] % mod) * (p[i - j] % mod)) % mod + mod) % mod;
        }

        cout << good[m] << endl;
    }

    return 0;
}
