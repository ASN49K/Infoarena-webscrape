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
int n, m, s, d;
edge muc[25005];
vector<pair<int, int>> v[355];
int init_cost[355];
int in_queue[355];

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

signed main()
{
    in>>n>>m>>s>>d;

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

//    ok = 1;
//    while(ok == 1)
//    {
//        ok = 0;
//
//        for(int i = 1; i<=n; i++)
//        {
//            dist[i] = INF;
//            from[i] = {0, 0, 0};
//        }
//
//        bellmanford();
//    }
//
//    out<<ans;

    return 0;
}
