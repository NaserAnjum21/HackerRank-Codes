#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 2e5 + 5;

int n, m, x, y, t, s;
set<int> unvis;
set<int> adj[N];
int dist[N];

void Init()
{
    memset(dist, -1, sizeof(dist));
    unvis.clear();

    for(int i = 0; i < N;i++)
        adj[i].clear();
}

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    unvis.erase(src);

    while (!q.empty() and !unvis.empty())
    {
        int u = q.front();
        q.pop();
        
        set<int>:: iterator it, temp;
        it = unvis.begin();

        while(it!= unvis.end())
        {
            int v = *it;
            if (adj[u].find(v) != adj[u].end())
            {
                ++it;
                continue;
            }
            temp = it;
            ++temp;
            q.push(v);
            dist[v] = dist[u] + 1;
            unvis.erase(v);
            it = temp;
            if (unvis.empty())
                return;
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
            adj[x].insert(y);
            adj[y].insert(x);
        }

        cin >> s;

        for (int i = 1; i <= n; i++)
            unvis.insert(i);

        BFS(s);

        for (int i = 1; i <= n; i++)
            if (dist[i])
                cout << dist[i] << " ";

        cout << endl;
    }

    return 0;
}
