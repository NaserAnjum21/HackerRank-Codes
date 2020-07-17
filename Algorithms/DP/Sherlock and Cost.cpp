#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 2e5 + 5;
int t, a, b, c, d, n, m, k, p, q, x, y, ans;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    freopen("input.txt", "r", stdin);

    cin >> t;

    while (t--)
    {
        cin >> n;

        int b[n + 1];

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        int dp[n + 2][2];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + abs(1 - b[i - 1]));
            dp[i][1] = max(dp[i - 1][0] + abs(b[i] - 1), dp[i - 1][1] + abs(b[i] - b[i - 1]));
        }

        cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
    }

    return 0;
}
