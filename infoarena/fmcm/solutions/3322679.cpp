#include <bits/stdc++.h>

using namespace std;

ifstream f("fmcm.in");
ofstream g("fmcm.out");

struct muchii{
    int node, cost;
};

struct compare{
    bool operator()(muchii a, muchii b){
        return a.cost > b.cost;
    }
};

const int inf = 1e9;
int n,m,source,sink, inque[500],old_dist[500],real_dist[500],dist[500],flow[500][500],cap[500][500],cost[500][500],tata[500];
vector <int> edges[500];
queue <int> q;
priority_queue <muchii, vector<muchii>, compare> pq;

bool dijkstra(){
    for(int i=1; i<=n; i++)
        dist[i]=inf, tata[i]=i;
    dist[source]=0;
    pq.push({source, 0});
    while(!pq.empty())
    {
        muchii x=pq.top();
        pq.pop();
        if(x.cost == dist[x.node])
            for(auto y:edges[x.node])
            {
                int new_cost = old_dist[x.node] - old_dist[y] + cost[x.node][y];
                if(dist[y] > dist[x.node]+new_cost and flow[x.node][y] < cap[x.node][y])
                {
                    dist[y] = dist[x.node] + new_cost;
                    real_dist[y] = real_dist[x.node] + cost[x.node][y];
                    tata[y] = x.node;
                    pq.push({y, dist[y]});
                }
            }
    }
    return dist[sink]!=inf;
}

void bellmanford(){
    for(int i=1; i<=n; i++)
        old_dist[i] = inf;
    old_dist[source] = 0;
    q.push(source);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        inque[x] = 0;
        for(auto y:edges[x])
            if(cap[x][y] != 0 and old_dist[y] > old_dist[x]+cost[x][y])
            {
                old_dist[y] = old_dist[x]+cost[x][y];
                if(inque[y] == 0)
                    inque[y]=1, q.push(y);
            }
    }
}

int main()
{
    f>>n>>m>>source>>sink;
    for(int i=1; i<=m; i++)
    {
        int x,y,c,z;
        f>>x>>y>>c>>z;
        edges[x].push_back(y);
        edges[y].push_back(x);
        cap[x][y]=c;
        cost[x][y] += z;
        cost[y][x] -= z;
    }
    int totalflow = 0, totalcost = 0;
    bellmanford();
    while(dijkstra())
    {
        int minim = inf;
        for(int i=sink; i!=source; i=tata[i])
            minim = min(minim, cap[tata[i]][i] - flow[tata[i]][i]);
        totalflow += minim;
        totalcost += minim * real_dist[sink];
        for(int i=sink; i!=source; i=tata[i])
        {
            flow[tata[i]][i] += minim;
            flow[i][tata[i]] -= minim;
        }
        for(int i=1; i<=n; i++)
            old_dist[i] = real_dist[i];
    }
    g<<totalcost<<' ';
    return 0;
}
