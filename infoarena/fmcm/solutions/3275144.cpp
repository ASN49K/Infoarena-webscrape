#include <fstream>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

#define int long long

struct el
{
    int dest, ind, cost;
};

struct el2
{
    int nod, ind, cost;
};

ifstream in("fmcm.in");
ofstream out("fmcm.out");
int n, m, s, d, ok, ans;
vector<el> v[355];
pair<int, int> muc[25005];
int initdist[355];
el2 from[355];
int INF = (1LL << 60);

void bellmanford()
{
    queue<int> q;
    q.push(s);
    initdist[s] = 0;

    while(!q.empty())
    {
        int nod = q.front();
        q.pop();



        for(auto it: v[nod])
        {
            if(initdist[it.dest] > initdist[nod] + it.cost && muc[it.ind].second != 0)
            {
                //cout<<it.dest<<'\n';
                initdist[it.dest] = initdist[nod] + it.cost;
                q.push(it.dest);
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

        v[x].push_back({y, i, t});
        muc[i] = {0, z};

        v[y].push_back({x, i + m, -t});
        muc[i + m] = {0, 0};
    }

    for(int i = 1; i<=n; i++)
    {
        initdist[i] = INF;
    }
    bellmanford();


    return 0;
}
