#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 1e5 + 5;

int n, m, x, y, id;
vector<int> adj[N];
vector<int> comps;
bool vis[N];

void dfs(int u)
{
    vis[u] = 1;
    comps[comps.size() - 1]++;

    for (int v : adj[u])
    {
        if (!vis[v])
            dfs(v);
    }
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

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            comps.push_back(0);
            dfs(i);
        }
    }

    LL ans = 0;

    for (int c : comps)
        ans += c * (n - c);

    cout << ans / 2 << endl;

    return 0;
}
