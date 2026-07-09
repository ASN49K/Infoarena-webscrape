#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define ll long long
#define N 100003
using namespace std;
ifstream f("paths.in");
ofstream w("paths.out");

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree< ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
ordered_set s;
ordered_set::iterator it;

int n,i,k,x,y,j,m;
int viz[N], tata[N], fiu[N];
ll maxi[N], sol, c, d[N], rez[N];
vector< pair<int,int> > g[N];

void park(int nod)
{
    viz[nod] = 1;
    maxi[nod] = 0;
    int h, fmax = 0,ok = 0;
    ll x;
    for(h = 0; h < g[nod].size(); h++)
        if(viz[g[nod][h].first] != 1)
    {
        ok = 1;
        tata[g[nod][h].first] = nod;
        park(g[nod][h].first);
        if(maxi[g[nod][h].first]+g[nod][h].second >= maxi[nod])
        {
            maxi[nod] = maxi[g[nod][h].first]+g[nod][h].second;
            fmax = h;
        }
    }
    if(ok)
    {
        for(h = 0; h < g[nod].size(); h++)
            if((g[nod][h].first != tata[nod])and(g[nod][h].first != g[nod][fmax].first))
            {
                x = maxi[g[nod][h].first]+g[nod][h].second;
                s.insert(-x);
            }

    }
}

void fly(int nod, ll su)
{
    viz[nod] = 2;
    int h,u;
    ll x,oldsu,val,maxim;
    for(h = 0; h < g[nod].size(); h++)
        if(viz[g[nod][h].first] != 2)
        {
            oldsu = su;
            val = *(s.find_by_order(k-1));
            if(-g[nod][h].second-maxi[g[nod][h].first] <= val)
                su = su-g[nod][h].second-maxi[g[nod][h].first]-(*(s.find_by_order(k)));
            s.erase(s.find_by_order(s.order_of_key(-g[nod][h].second-maxi[g[nod][h].first])));
            maxim = -1;
            for(u = 0; u < g[nod].size(); u++)
                if((g[nod][u].first != tata[nod])and(u != h))
                if(maxi[g[nod][u].first]+g[nod][u].second > maxim)
                maxim = maxi[g[nod][u].first]+g[nod][u].second;

            if(maxim != -1)
            {

                val = *(s.find_by_order(k-1));
                if(-maxim <= val)
                    su  = su -maxim-(*(s.find_by_order(k)));
                s.erase(s.find_by_order(s.order_of_key(-maxim)));

                val = *(s.find_by_order(k-1));
                if(-maxim-g[nod][h].second <= val)
                    su = su+maxim+g[nod][h].second+val;
                s.insert(-maxim-g[nod][h].second);

            }
            rez[g[nod][h].first] = su;
            fly(g[nod][h].first,su);
            su = oldsu;
            s.insert(-g[nod][h].second-maxi[g[nod][h].first]);
            s.insert(-maxim);
            s.erase(s.find_by_order(s.order_of_key(-maxim-g[nod][h].second)));
        }
}

void solve()
{
    park(1);
    s.insert(-maxi[1]);

    rez[1] = 0;
    i = 1;
    for(it = s.begin(); it != s.end(); it++)
        if(i <= k) {rez[1] -= (*it); i++; }
        else break;

    fly(1,rez[1]);

    for(i = 1; i <= n; i++)
        w << rez[i] << "\n";
}

int main()
{
    f >> n >> k;
    for(i = 1; i < n; i++)
    {
        f >> x >> y >> c;
        g[x].push_back({y,c});
        g[y].push_back({x,c});
    }
    solve();
    return 0;
}
