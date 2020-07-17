#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 1e2 + 7;

int n, m, x, y, t;
vector<int> adj[N];
int dist[N];
int jump[N];
bool vis[N];

void Init()
{
    memset(vis, 0, sizeof(vis));
    memset(jump, 0, sizeof(jump));
    memset(dist, 0, sizeof(dist));
    for (int i = 0; i < N; i++)
        adj[i].clear();

}

void AddEdges()
{
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i + j > 100)
                continue;

            int dest = jump[i+j] == 0 ? i + j: jump[i+j];
            adj[i].push_back(dest);
        }
    }
}

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (vis[v])
                continue;
            
            q.push(v);
            vis[v] = 1;
            dist[v] = dist[u] + 1;
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
        
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            jump[x] = y;
        }

        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            jump[x] = y;
        }

        AddEdges();

        BFS(1);

        if (dist[100] == 0)
            dist[100] = -1;

        cout << dist[100] << endl;
    }

    return 0;
}
