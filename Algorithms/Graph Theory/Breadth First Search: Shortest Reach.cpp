#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 1e3 + 5;

int n, m, x, y, t, s;
vector<int> adj[N];
int dist[N];

void Init()
{
    for (int i = 0; i < N; i++)
        adj[i].clear();
    memset(dist, -1, sizeof(dist));
}

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (dist[v] != -1)
                continue;

            q.push(v);
            dist[v] = dist[u] + 6;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> t;

    while (t--)
    {
        Init();

        cin >> n >> m;

        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        cin >> s;

        BFS(s);

        for (int i = 1; i <= n; i++)
        {
            if (dist[i])
                cout << dist[i] << " ";
        }
        cout << endl;

    }

    return 0;
}
