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
        while(1)
        {
            bool steag = 0;
            for(int j = 0; j < edge.size(); j ++)
                if(edge[j].cap > 0 && dist[edge[j].from] + edge[j].cost < dist[edge[j].to])
                {
                    dist[edge[j].to] = dist[edge[j].from] + edge[j].cost;
                    vine[edge[j].to] = j;
                    steag = 1;
                }
            if(!steag)
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
            for(int i = prec[g]; i != -1; i = edge[i].prec)
                if(edge[i].cap > 0 && real[edge[i].to] > real[g] + edge[i].cost)
                {
                    real[edge[i].to] = real[g] + edge[i].cost;
                    pq.push({-(dist[g] + edge[i].cost - h[edge[i].to] + h[g]), {edge[i].to, i}});
                }
        }
        h = real;
        return dist[d] != inf;
    }
    pair<int, int> push(int s, int d)
    {
        pair<int, int> p;
        int x = d, minn = inf;
        while(x != s)
        {
            minn = min(minn, edge[vine[x]].cap);
            x = edge[vine[x]].from;
        }
        p.first = minn;
        x = d;
        while(x != s)
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
        if(!bellman(s, d))
            return {0, 0};
        while(dijkstra(s, d))
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
    for(int i = 0; i < m; i ++)
    {
        int u, v, cap, cost;
        cin >> u >> v >> cap >> cost;
        g.baga(u, v, cap, cost);
    }
    cout << g.fmcm(s, d).second << '\n';
}
