#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 1e5 + 5;

int n, m, x, y, id;
vector<int> adj[N];
bool vis[N];
int subtree[N];

int dfs(int u)
{
    vis[u] = 1;
    subtree[u] = 1;

    for (int v : adj[u])
    {
        if (!vis[v])
            subtree[u] += dfs(v);
    }
    return subtree[u];
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);

    int ans = 0;

    for (int i = 2; i <= n; i++)
    {
        if (subtree[i] % 2 == 0)
            ans++;
    }

    cout << ans << endl;

    return 0;
}
