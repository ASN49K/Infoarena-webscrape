#include <fstream>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

#define int long long

struct edge
{
    int cap, cost;
};

ifstream in("fmcm.in");
ofstream out("fmcm.out");
int n, m, source, dest, ans;
edge muc[25005];
vector<pair<int, int>> v[355];
int init_cost[355];
int in_queue[355];
int cost[355];
pair<int, int> from[355];
int INF = (1 << 30);

void bellman_ford()
{
    queue<int> q;
    for(int i = 1; i<=n; i++)
    {
        init_cost[i] = 0;
        in_queue[i] = 1;
        q.push(i);
    }

    while(!q.empty())
    {
        int nod = q.front();

        q.pop();
        in_queue[nod] = 0;

        for(auto it: v[nod])
        {
            if(muc[it.second].cap > 0 && init_cost[nod] + muc[it.second].cost < init_cost[it.first])
            {
                init_cost[it.first] = init_cost[nod] + muc[it.second].cost;

                if(in_queue[it.first] == 0)
                {
                    in_queue[it.first] = 1;
                    q.push(it.first);
                }
            }
        }
    }
}

int dijkstra()
{
    for(int i = 1; i<=n; i++)
    {
        cost[i] = INF;
        from[i] = {0, 0};
    }

    cost[source] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, source});

    while(!pq.empty())
    {
        int d = -pq.top().first;
        int nod = pq.top().second;

        pq.pop();

        if(d != cost[nod])
        {
            continue;
        }

        for(auto it: v[nod])
        {
            if(muc[it.second].cap > 0 && d + muc[it.second].cost + init_cost[nod] - init_cost[it.first] < cost[it.first])
            {
                cost[it.first] = d + muc[it.second].cost + init_cost[nod] - init_cost[it.first];
                from[it.first] = {nod, it.second};
                pq.push({-cost[it.first], it.first});
            }
        }
    }

    return (cost[dest] != INF);
}

signed main()
{
    in>>n>>m>>source>>dest;

    int x, y, z, t;
    for(int i = 1; i<=m; i++)
    {
        in>>x>>y>>z>>t;

        v[x].push_back({y, i});
        muc[i] = {z, t};

        v[y].push_back({x, i + m});
        muc[i + m] = {0, -t};
    }

    bellman_ford();

    while(dijkstra())
    {
        for(int i = 1; i<=n; i++)
        {
            if(cost[i] != INF)
            {
                init_cost[i] += cost[i];
            }
        }

        int flux = INF;
        int nod = dest;

        while(nod != source)
        {
            flux = min(flux, muc[from[nod].second].cap);
            nod = from[nod].first;
        }

        ans += flux * init_cost[dest];

        nod = dest;
        while(nod != source)
        {
            if(from[nod].second <= m)
            {
                muc[from[nod].second].cap -= flux;
                muc[from[nod].second + m].cap += flux;
            }
            else
            {
                muc[from[nod].second].cap -= flux;
                muc[from[nod].second - m].cap += flux;
            }

            nod = from[nod].first;
        }
    }

    out<<ans;

    return 0;
}
