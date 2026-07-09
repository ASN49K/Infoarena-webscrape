#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct Dinic
{
    int n;
    struct edge
    {
        int from, to, cost, cap;
    };
    vector<edge> muchii;
    vector<vector<int>> edges;
    vector<bool> viz;
    vector<int> prv, dist;
    Dinic(int N)
    {
        n = N;
        edges.resize(n);
        viz.resize(n);
        dist.resize(n);
        prv.resize(n);
    }
    void addEdge(int from, int to, int cost, int cap)
    {
        edges[from].push_back(muchii.size());
        muchii.push_back({from, to, cost, cap});
        edges[to].push_back(muchii.size());
        muchii.push_back({to, from, -cost, 0});
    }
    bool bellman(int source, int dest)
    {
        for(int i = 0; i < n; i ++)
            dist[i] = INF;
        vector<bool> inQ(n);
        queue<int> q;
        q.push(source);
        dist[source] = 0;
        while(!q.empty())
        {
            int node = q.front();
            inQ[node] = false;
            q.pop();
            for(auto i : edges[node])
            {
                edge e = muchii[i];
                if(e.cap && dist[node] + e.cost < dist[e.to])
                {
                    dist[e.to] = dist[node] + e.cost;
                    if(!inQ[e.to])
                    {
                        q.push(e.to);
                        inQ[e.to] = true;
                    }
                }
            }
        }
        return dist[dest] != INF;
    }
    bool dijkstra(int source, int dest)
    {
        vector<bool> viz(n, 0);
        vector<int> fakeDist(n, INF);
        vector<int> realDist(n);
        for(int i = 0; i < n; i ++)
        {
            realDist[i] = dist[i];
            prv[i] = -1;
        }
        priority_queue<pair<int, int>> pq;
        pq.push({0, source});
        dist[source] = fakeDist[source] = 0;
        while(!pq.empty())
        {
            int node = pq.top().second;
            pq.pop();
            if(!viz[node])
            {
                viz[node] = true;
                for(auto i : edges[node])
                {
                    edge e = muchii[i];
                    if(e.cap && fakeDist[node] + realDist[node] + e.cost - realDist[e.to] < fakeDist[e.to])
                    {
                        fakeDist[e.to] = fakeDist[node] + realDist[node] + e.cost - realDist[e.to];
                        dist[e.to] = dist[node] + e.cost;
                        prv[e.to] = i;
                        pq.push({-fakeDist[e.to], e.to});
                    }
                }
            }
        }
        return fakeDist[dest] != INF;
    }
    pair<int, int> push(int source, int dest)
    {
        int flow = INF, c = 0;
        for(int node = dest; node != source; node = muchii[prv[node]].from)
        {
            flow = min(flow, muchii[prv[node]].cap);
            c += muchii[prv[node]].cost;
        }
        for(int node = dest; node != source; node = muchii[prv[node]].from)
        {
            muchii[prv[node]].cap -= flow;
            muchii[prv[node] ^ 1].cap += flow;
        }
        return {flow, flow * c};
    }
    pair<int, int> maxFlowMinCost( int source, int dest )
    {
        int maxFlow = 0, minCost = 0;
        if(!bellman(source, dest))
            return {0, 0};
        while(dijkstra(source, dest))
        {
            auto p = push(source, dest);
            maxFlow += p.first;
            minCost += p.second;
        }
        return {maxFlow, minCost};
    }
};


int main()
{
    ifstream cin("fmcm.in");
    ofstream cout("fmcm.out");
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    Dinic ds(n);
    for(int i = 0, from, to, cap, cost; i < m; i ++)
    {
        cin >> from >> to >> cap >> cost;
        ds.addEdge(from - 1, to - 1, cost, cap);
    }
    cout << ds.maxFlowMinCost(s - 1, d - 1).second;
    return 0;
}
