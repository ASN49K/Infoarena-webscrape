#include <bits/stdc++.h>
using namespace std;
ifstream fin("fmcm.in");
ofstream fout("fmcm.out");
const int NMAX = 351, INF = 1e9;
int n, m, sursa, dest, dif[NMAX], dist[NMAX], capacity[NMAX][NMAX], cost[NMAX][NMAX], parent[NMAX];
bool in_queue[NMAX];
vector<int> adj[NMAX];

void bellman(int sursa)
{
    fill(dif + 1, dif + n + 1, INF);
    queue<int> Q({sursa});
    in_queue[sursa] = true;
    dif[sursa] = 0;
    while(!Q.empty())
    {
        int node = Q.front(); Q.pop(); in_queue[node] = false;
        for(int next : adj[node])
        {
            if(dif[node] + cost[node][next] < dif[next] && capacity[node][next] > 0)
            {
                dif[next] = dif[node] + cost[node][next];
                if(in_queue[next])
                    continue;
                Q.push(next);
                in_queue[next] = true;
            }
        }
    }
}

inline int delta(int u, int v)
{
    return (dif[v] - dif[u]);
}

bool dijkstra(int sursa, int dest)
{
    fill(dist + 1, dist + n + 1, INF);
    memset(parent, 0, sizeof(parent));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, sursa});
    while(!pq.empty())
    {
        auto [_, node] = pq.top(); pq.pop();
        for(int next : adj[node])
        {
            if(dist[node] + delta(node, next) < dist[next] && capacity[node][next] > 0)
            {
                dist[next] = dist[node] + delta(node, next);
                parent[next] = node;
                pq.push({dist[next], next});
            }
        }
    }
    return (parent[dest] != 0);
}

pair<int, int> maxflow(int sursa, int dest)
{
    bellman(sursa);
    int flow = 0, mincost = 0;
    while(dijkstra(sursa, dest))
    {
        int node = dest, path_flow = INF;
        while(node != sursa)
        {
            path_flow = min(path_flow, capacity[parent[node]][node]);
            node = parent[node];
        }
        node = dest;
        while(node != sursa)
        {
            capacity[parent[node]][node] -= path_flow;
            capacity[node][parent[node]] += path_flow;
            mincost += path_flow * cost[parent[node]][node];
            node = parent[node];
        }
        flow += path_flow;
    }
    return {flow, mincost};
}

int main()
{
    fin >> n >> m >> sursa >> dest;
    while(m--)
    {
        int u, v, cap, c;
        fin >> u >> v >> cap >> c;
        adj[u].push_back(v);
        capacity[u][v] = cap;
        cost[u][v] = c;
        adj[v].push_back(u);
        capacity[v][u] = 0;
        cost[v][u] = -c;
    }
    fout << maxflow(sursa, dest).second;

    return 0;
}
