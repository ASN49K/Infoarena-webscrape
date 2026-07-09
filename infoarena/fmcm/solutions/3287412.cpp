#include <bits/stdc++.h>
#pragma GCC optimize("O3", "Ofast", "unroll-loops")

using namespace std;

using ll = long long;
// #define int ll
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1}; // N S E V
const int MAXN = 305 + 5;

struct fmcm
{
    struct Edge
    {
        int u, v, cap, cost;
    };

    vector<Edge> e;
    vector<vector<int>> adj;
    vector<int> fd;
    int cnt = 0;

    void init()
    {
        e.clear();
        adj.clear();
        fd.clear();
        cnt = 0;
    }

    int add_node()
    {
        adj.push_back({});
        fd.push_back(0);
        return cnt++;
    }

    void add_edge(int u, int v, int cap, int cost)
    {
        adj[u].push_back(e.size());
        e.push_back({u, v, cap, cost});
        adj[v].push_back(e.size());
        e.push_back({v, u, 0, -cost});
    }

    void bellman(int s)
    {
        for(int i = 0; i < cnt; i++)
            fd[i] = INF;
        fd[s] = 0;
        for(int _ = 0; _ < cnt; _++)
        {
            for(auto [u, v, cap, cost] : e)
            {
                if(cap)
                    fd[v] = min(fd[v], fd[u] + cost);
            }
        }
        for(auto [u, v, cap, cost] : e)
        {
            if(cap && cost + fd[u] - fd[v] < 0)
            {
                assert(false);
            }
        }
    }

    int dijkstra(int s, int t)
    {
        priority_queue<pii> pq; // cost, nod
        pq.push({0, s});
        vector<bool> visited;
        visited.resize(cnt);
        vector<int> dist;
        dist.assign(cnt, INF);
        vector<int> parent; // tin edgeul
        parent.resize(cnt);
        dist[s] = 0;
        while(!pq.empty())
        {
            int d = -pq.top().first, u = pq.top().second;
            pq.pop();
            // if(visited[u])
            //     continue;
            visited[u] = true;
            for(int j : adj[u])
            {
                int newd = d + e[j].cost + fd[u] - fd[e[j].v];
                if(e[j].cap && newd < dist[e[j].v])
                {
                    dist[e[j].v] = newd;
                    parent[e[j].v] = j;
                    pq.push({-newd, e[j].v});
                }
            }
        }
        if(!visited[t]) // fail
            return 0;
        for(int i = 0; i < cnt; i++)
        {
            dist[i] += fd[i];
        }
        int flow = INF;
        for(int i = t; i != s; )
        {
            flow = min(flow, e[parent[i]].cap);
            i = e[parent[i]].u;
        }
        for(int i = t; i != s; )
        {
            e[parent[i]].cap -= flow;
            e[parent[i] ^ 1].cap += flow;
            i = e[parent[i]].u;
        }
        return flow * dist[t];
    }

    int flow(int s, int t)
    {
        bellman(s);
        int ans = 0;
        int res = 0;
        while(res = dijkstra(s, t))
        {
            ans += res;
        }
        return ans;
    }
};

fmcm fm;

int n, m, s, d;

int32_t main()
{
    #ifndef LOCAL
        ifstream cin("fmcm.in");
        ofstream cout("fmcm.out");
    #endif
    cin >> n >> m >> s >> d;
    for(int i = 0; i < n; i++)
    {
        fm.add_node();
    }
    for(int i = 1; i <= m; i++)
    {
        int x, y, c, z;
        cin >> x >> y >> c >> z;
        fm.add_edge(x - 1, y - 1, c, z);
    }
    cout << fm.flow(s - 1, d - 1);
    return 0;
}