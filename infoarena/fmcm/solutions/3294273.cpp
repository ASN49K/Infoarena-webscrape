// min cost max flow algo
#pragma GCC  optimize("O3")
#pragma GCC optimize("fast-math")
#pragma GCC  optimize("unroll-loops")
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define pb push_back
#define pq priority_queue
using namespace std;
const int dim = 355;
int n, m, x, y, cost, cap, src, sink;
ll sol;
int old[dim], rel[dim], dist[dim], costu[dim][dim], capu[dim][dim], tata[dim];

bool viz[dim];
vector<int>adj[dim];
//vector<vector<int> >adj;

void belm()
{
    for(int i = 1; i <= n; ++i)
        old[i] = inf;
    old[src] = 0;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int nod = q.front();
        q.pop();
        for(auto it: adj[nod])
        {
            if(capu[nod][it] > 0 && old[it] > old[nod] + costu[nod][it])
            {
                q.push(it);
                old[it] = old[nod] + costu[nod][it];
            }
        }
    }
}
bool dijkstra()
{
    for(int i = 1; i <= n; ++i)
    {
        rel[i] = inf, viz[i] = 0, dist[i] = inf;
        tata[i] = 0;
    }
    dist[src] = 0, rel[src] = 0;
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, src});
    while(!q.empty())
    {
        int nod = q.top().second;
        //int d = pq.top().first;
        q.pop();
        if(viz[nod])
            continue;
        viz[nod] = 1;
        for(auto it : adj[nod])
        {
            if(capu[nod][it] > 0 && dist[it] > dist[nod] + costu[nod][it] + old[nod] - old[it])
            {
                dist[it] = dist[nod] + costu[nod][it] + old[nod] - old[it];
                rel[it] = rel[nod] + costu[nod][it];
                q.push({dist[it], it});
                tata[it] = nod;
            }
        }
    }
    if(dist[sink] == inf)
        return 0;
    for(int i = 1; i <= n; ++i)
        old[i] = rel[i];
    int mini  = inf;
    for(int i = sink; i != src; i = tata[i])
        mini = min(mini, capu[tata[i]][i]);
    sol = sol + 1ll * mini * rel[sink];
    for(int i = sink; i != src; i = tata[i])
    {
       capu[tata[i]][i] -= mini;
       capu[i][tata[i]] += mini;
    }
    return 1;

}
ifstream fin("fmcm.in");
ofstream fout("fmcm.out");
int main()
{
    fin >> n >> m;
   // adj.resize(n, vector<int>());
    //viz.resize(n, false);
    fin >> src >> sink;
    for(int i = 1; i <= m; ++i)
    {
        fin  >> x >> y >> cap >> cost;
        adj[x].pb(y);
        adj[y].pb(x);
        capu[x][y] = cap;
        costu[x][y] = cost;
        costu[y][x] = -cost;
    }
    belm();
    while(dijkstra());
    fout << sol;
    return 0;

}
