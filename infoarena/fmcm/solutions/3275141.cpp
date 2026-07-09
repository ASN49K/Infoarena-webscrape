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
int dist[355];
el2 from[355];
int INF = (1LL << 60);

void bellmanford()
{
    //cout<<"a";
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    from[s] = {-1, -1, -1};

    while(!q.empty())
    {
        int nod = q.front();
        q.pop();

        //cout<<nod<<'\n';

        for(auto it: v[nod])
        {
            //cout<<it.dest<<" "<<it.ind<<" "<<it.cost<<'\n';
            if(dist[it.dest] > dist[nod] + it.cost && muc[it.ind].second - muc[it.ind].first > 0)
            {
                //cout<<it.dest<<'\n';
                dist[it.dest] = dist[nod] + it.cost;
                from[it.dest] = {nod, it.ind, it.cost};

                q.push(it.dest);
            }
        }
    }

    //cout<<"a";

    if(dist[d] == INF)
    {
        return;
    }
    ok = 1;

    int flux = INF;
    int nod = d;

    while(from[nod].nod != -1)
    {
        flux = min(flux, muc[from[nod].ind].second - muc[from[nod].ind].first);

        nod = from[nod].nod;
    }

    int add = 0;
    nod = d;

    while(from[nod].nod != -1)
    {
        add += flux * from[nod].cost;

        if(from[nod].ind <= m)
        {
            muc[from[nod].ind].first += flux;
            muc[from[nod].ind + m].first -= flux;
        }
        else
        {
            muc[from[nod].ind].first += flux;
            muc[from[nod].ind - m].first -= flux;
        }

        nod = from[nod].nod;
    }

    ans += add;
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

    ok = 1;
    while(ok == 1)
    {
        ok = 0;

        for(int i = 1; i<=n; i++)
        {
            dist[i] = INF;
            from[i] = {0, 0, 0};
        }

        bellmanford();
    }

    out<<ans;

    return 0;
}
