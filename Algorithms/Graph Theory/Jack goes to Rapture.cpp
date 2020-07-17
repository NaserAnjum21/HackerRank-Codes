#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 5e4 + 5;
const int INF = INT_MAX;
int n, m, x, y, z;
vector<pair<int, int>> adj[N];
bool vis[N];
int dist[N];

void Djikstra(int src)
{
    memset(vis, 0, sizeof(vis));
    fill(dist, dist + N, INF);

    dist[src] = 0;
    //priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq; //why it doesn't work!?
    set<pair<int,int>> pq;
    pq.insert({dist[src], src});

    while (!pq.empty())
    {
        pair<int,int> pii = *(pq.begin());
        int u = pii.second;
        pq.erase(pq.begin());
        if (vis[u])
            continue;

        vis[u] = 1;

        for (auto p : adj[u])
        {
            int v = p.first;
            int w = p.second;
            int ndist = dist[u] + max(0, w - dist[u]);
            if (dist[v] > ndist)
            {
                dist[v] = ndist;
                pq.insert({dist[v], v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }

    Djikstra(1);

    if(dist[n] == INF)
        cout<<"NO PATH EXISTS"<<endl;
    else
        cout<<dist[n]<<endl;

    return 0;
}
