#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 2e5 + 5;
const LL mod = 1e9 + 7;
LL t, a, b, c, d, n, m, k, p, q, x, y, ans;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    //freopen("input.txt", "r", stdin);

    string str;
    cin >> str;

    int n = str.size();

    int dp[10][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= 9; i++)
    {
        LL prod = i;
        for (int k = 1; k <= n; k++)
        {
            dp[i][k] = (dp[i][k - 1] % mod + prod % mod) % mod;
            prod = (prod * 10) % mod;
        }
    }

    LL sum = 0;
    for (int i = 0; i < n; i++)
    {
        int digit = str[i] - '0';
        LL add = ((i + 1) % mod * dp[digit][n - i] % mod) % mod;
        sum = (sum + add) % mod;
    }

    cout<< sum <<endl;

    return 0;
}
