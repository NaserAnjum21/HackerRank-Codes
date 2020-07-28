#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 52;
const int MX = 5e5;
int n, m, k;
string grid[N];
int dp[N][N][1002];

int Solve(int x, int y, int k)
{
    if (x < 0 or y < 0 or x >= n or y >= m or k < 0)
        return INT_MAX;
    if (grid[x][y] == '*')
        return 0;

    if (dp[x][y][k] != -1)
        return dp[x][y][k];

    int u = Solve(x - 1, y, k - 1);
    int d = Solve(x + 1, y, k - 1);
    int l = Solve(x, y - 1, k - 1);
    int r = Solve(x, y + 1, k - 1);

    u += (u == INT_MAX) ? 0 : grid[x][y] != 'U';
    d += (d == INT_MAX) ? 0 : grid[x][y] != 'D';
    l += (l == INT_MAX) ? 0 : grid[x][y] != 'L';
    r += (r == INT_MAX) ? 0 : grid[x][y] != 'R';

    return dp[x][y][k] = min(min(u, d), min(l, r));
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
        cin >> grid[i];

    memset(dp, -1, sizeof(dp));

    int ans = Solve(0, 0, k);
    if (ans == INT_MAX)
        ans = -1;

    cout << ans << endl;

    return 0;
}
