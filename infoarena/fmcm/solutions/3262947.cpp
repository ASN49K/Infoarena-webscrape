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
        dist.resize(n);
        vine.resize(n);
        h.resize(n, inf);
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
        dist[s] = 0;
        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j < edge.size(); j ++)
                if(edge[j].cap > 0 && dist[edge[j].from] + edge[j].cost < dist[edge[j].to])
                {
                    dist[edge[j].to] = dist[edge[j].from] + edge[j].cost;
                    vine[edge[j].to] = j;
                }
        }
        h = dist;
        return h[d] != inf;
    }
    int dijkstra(int s, int d)
    {
        dist.assign(n, inf);
        vector<bool> f(n, false);
        dist[s] = 0;
        vector<int> real(n, inf);
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {s, -1}});
        real[s] = 0;
        while(!pq.empty())
        {
            auto x = pq.top();
            pq.pop();
            int g = x.second.first;
            if(f[g])
                continue;
            vine[g] = x.second.second;
            f[g] = true;
            dist[g] = -x.first;
            if(g != s)
                real[g] = real[edge[vine[g]].from] + edge[vine[g]].cost;
            for(int i = prec[g]; i != -1; i = edge[i].prec)
                if(edge[i].cap > 0 && !f[edge[i].to])
                    pq.push({-(dist[g] + edge[i].cost - h[edge[i].to] + h[g]), {edge[i].to, i}});
        }
        if(dist[d] == inf)
            return 0;
        int y = d, minn = inf;
        while(y != s)
        {
            minn = min(minn, edge[vine[y]].cap);
            y = edge[vine[y]].from;
        }
        h = real;
        return minn;
    }
    pair<int, int> fmcm(int s, int d)
    {
        int flux = 0, cost = 0;
        if(!bellman(s, d))
            return {0, 0};
        int x = dijkstra(s, d);
        while(x)
        {
            flux += x;
            int y = d;
            while(y != s)
            {
                edge[vine[y]].cap -= x;
                edge[vine[y] ^ 1].cap += x;
                cost += x * edge[vine[y]].cost;
                y = edge[vine[y]].from;
            }
            x = dijkstra(s, d);
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
    for(int i = 0; i < m; i ++)
    {
        int u, v, cap, cost;
        cin >> u >> v >> cap >> cost;
        g.baga(u, v, cap, cost);
    }
    cout << g.fmcm(s, d).second << '\n';
}
