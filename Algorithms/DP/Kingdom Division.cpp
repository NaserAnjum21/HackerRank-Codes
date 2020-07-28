#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 1e5 + 5;
const LL mod = 1e9 + 7;
int n, u, v;
vector<int> adj[N];
vector<bool> vis(N, 0);
LL dp[N][2];

void dfs(int u)
{
    vis[u] = 1;
    LL s0 = 1, s1 = 1;
    for (int v : adj[u])
    {
        if (vis[v])
            continue;
        dfs(v);
        s0 = (s0 % mod * (2 * dp[v][0]+ dp[v][1]) % mod) % mod;
        s1 = (s1 * dp[v][0]) % mod;
    }
    s0 = (s0 - s1 + mod) % mod;
    dp[u][0] = s0;
    dp[u][1] = s1;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    cout << (2 * dp[1][0]) % mod << endl;

    return 0;
}
