#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 3e3 + 5;
int dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    //freopen("input.txt", "r", stdin);

    string str;

    cin >> str;

    int n = str.size();

    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    for (int L = 2; L <= n; L++)
    {
        for (int i = 0; i < n - L + 1; i++)
        {
            int j = i + L - 1;

            if (str[i] == str[j])
                dp[i][j] = 2 + ((i + 1 > j - 1) ? 0 : dp[i + 1][j - 1]);
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }

    int ans = 0;

    for (int i = 0; i < n - 1; i++)
    {
        ans = max(ans, dp[0][i] * dp[i + 1][n - 1]);
    }

    cout << ans << endl;

    return 0;
}
