#include <bits/stdc++.h>
using namespace std;
ifstream fin("fmcm.in");
ofstream fout("fmcm.out");
const int NMAX = 351, INF = 1e9;
int n, m, S, D;

struct MinCostMaxFlow
{
    struct edge
    {
        int u, v, capacity, cost;
    };
    vector<edge> edges;
    vector<int> adj[NMAX];
    int offset[NMAX], dist[NMAX], parent[NMAX];
    bool in_queue[NMAX];

    void add_edge(int u, int v, int capacity, int cost)
    {
        edges.push_back({u, v, capacity, cost});
        adj[u].push_back(edges.size() - 1);
        edges.push_back({v, u, 0, -cost});
        adj[v].push_back(edges.size() - 1);
    }

    bool bellman(int sursa, int dest)
    {
        fill(offset + 1, offset + n + 1, INF);
        offset[sursa] = 0;
        queue<int> q({sursa});
        memset(in_queue, false, sizeof(in_queue));
        in_queue[sursa] = true;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            in_queue[node] = false;
            for(int idx : adj[node])
            {
                edge &muchie = edges[idx];
                if(muchie.capacity > 0 && offset[muchie.v] > offset[node] + muchie.cost)
                {
                    offset[muchie.v] = offset[node] + muchie.cost;
                    if(in_queue[muchie.v] == false)
                    {
                        q.push(muchie.v);
                        in_queue[muchie.v] = true;
                    }
                }
            }
        }
        return (offset[dest] != INF);
    }

    bool dijkstra(int sursa, int dest)
    {
        fill(dist + 1, dist + n + 1, INF);
        fill(parent + 1, parent + n + 1, -1);
        dist[sursa] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, sursa});
        while(!pq.empty())
        {
            auto [dist_crt, node] = pq.top();
            pq.pop();
            if(dist_crt > dist[node])
                continue;
            for(int idx : adj[node])
            {
                edge &muchie = edges[idx];
                if(muchie.capacity > 0)
                {
                    int offset_cost = muchie.cost + offset[node] - offset[muchie.v];
                    if(dist[node] + offset_cost < dist[muchie.v])
                    {
                        dist[muchie.v] = dist[node] + offset_cost;
                        parent[muchie.v] = idx;
                        pq.push({dist[muchie.v], muchie.v});
                    }
                }
            }
        }
        return (parent[dest] != -1);
    }

    pair<int, int> push_flow(int sursa, int dest)
    {
        int flow = INF, sum_cost = 0;
        for(int node = dest; node != sursa;)
        {
            int idx = parent[node];
            flow = min(flow, edges[idx].capacity);
            node = edges[idx].u;
        }
        for(int node = dest; node != sursa;)
        {
            int idx = parent[node];
            edges[idx].capacity -= flow;
            edges[idx ^ 1].capacity += flow;
            sum_cost += flow * edges[idx].cost;
            node = edges[idx].u;
        }
        return {flow, sum_cost};
    }

    pair<int, int> get_flow_cost(int sursa, int dest)
    {
        int max_flow = 0, min_cost = 0;
        if(bellman(sursa, dest) == false)
            return {0, 0};
        while(dijkstra(sursa, dest))
        {
            auto [flow, cost] = push_flow(sursa, dest);
            max_flow += flow;
            min_cost += cost;
            for(int i = 1; i <= n; i++)
                if(dist[i] != INF)
                    offset[i] += dist[i];
        }
        return {max_flow, min_cost};
    }
};
MinCostMaxFlow flow;

int main()
{
    fin >> n >> m >> S >> D;
    while(m--)
    {
        int u, v, capacity, cost;
        fin >> u >> v >> capacity >> cost;
        flow.add_edge(u, v, capacity, cost);
    }
    fout << flow.get_flow_cost(S, D).second;

    fin.close();
    fout.close();
    return 0;
}
