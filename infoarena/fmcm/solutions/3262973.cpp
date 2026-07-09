#include <ext/pb_ds/priority_queue.hpp>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
//#define int ll

struct Dinic
{
    int n;
    const int inf = 1e9;
    struct Edge
    {
        int from, to, cost, cap, prec;
    };
    vector<Edge> edge;
    vector<int> dist, h, prec, vine;
    Dinic(int N)
    {
        n = N + 5;
        dist.resize(n, inf);
        vine.resize(n);
        h.resize(n, 0); // Initialize h to 0 instead of inf
        prec.resize(n, -1);
    }
    void baga(int from, int to, int cap, int cost)
    {
        edge.push_back({from, to, cost, cap, prec[from]});
        prec[from] = edge.size() - 1;

        edge.push_back({to, from, -cost, 0, prec[to]});
        prec[to] = edge.size() - 1;
    }
    bool bellman(int s, int d)
    {
        dist.assign(n, inf); // Reset dist before Bellman-Ford
        dist[s] = 0;
        for (int iter = 0; iter < n; iter++) // Limit iterations to n
        {
            bool steag = 0;
            for (int j = 0; j < edge.size(); j++)
                if (edge[j].cap > 0 && dist[edge[j].from] + edge[j].cost < dist[edge[j].to])
                {
                    dist[edge[j].to] = dist[edge[j].from] + edge[j].cost;
                    vine[edge[j].to] = j;
                    steag = 1;
                }
            if (!steag)
                break;
        }
        h = dist;
        return h[d] != inf;
    }
    bool dijkstra(int s, int d)
    {
        dist.assign(n, inf);
        vector<bool> f(n, false);
        dist[s] = 0;
        __gnu_pbds::priority_queue<pair<int, int>, greater<>, __gnu_pbds::binary_heap_tag> pq; // Use pb_ds priority queue
        pq.push({0, s});
        while (!pq.empty())
        {
            auto [curr_cost, g] = pq.top();
            pq.pop();
            if (f[g])
                continue;
            f[g] = true;
            for (int i = prec[g]; i != -1; i = edge[i].prec)
            {
                auto &e = edge[i];
                int reduced_cost = curr_cost + e.cost + h[g] - h[e.to];
                if (e.cap > 0 && reduced_cost < dist[e.to])
                {
                    dist[e.to] = reduced_cost;
                    vine[e.to] = i;
                    pq.push({dist[e.to], e.to});
                }
            }
        }
        for (int i = 0; i < n; i++) // Update potentials
            if (dist[i] < inf)
                h[i] += dist[i];
        return dist[d] != inf;
    }
    pair<int, int> push(int s, int d)
    {
        pair<int, int> p;
        int x = d, minn = inf;
        while (x != s)
        {
            minn = min(minn, edge[vine[x]].cap);
            x = edge[vine[x]].from;
        }
        p.first = minn;
        x = d;
        while (x != s)
        {
            p.second += edge[vine[x]].cost * minn;
            edge[vine[x]].cap -= minn;
            edge[vine[x] ^ 1].cap += minn;
            x = edge[vine[x]].from;
        }
        return p;
    }
    pair<int, int> fmcm(int s, int d)
    {
        int flux = 0, cost = 0;
        if (!bellman(s, d))
            return {0, 0};
        while (dijkstra(s, d))
        {
            pair<int, int> p = push(s, d);
            flux += p.first;
            cost += p.second;
        }
        return {flux, cost};
    }
};

signed main()
{
    ifstream cin("fmcm.in");
    ofstream cout("fmcm.out");

    int n, m, s, d;
    cin >> n >> m >> s >> d;
    Dinic g(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, cap, cost;
        cin >> u >> v >> cap >> cost;
        g.baga(u, v, cap, cost);
    }
    cout << g.fmcm(s, d).second << '\n';
}
