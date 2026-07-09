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
int n,i,k,x,y,j,m;
int viz[N], tata[N], fiu[N];
ll maxi[N], sol, c, d[N], rez[N];
vector< pair<int,int> > g[N];
vector<ll> s;

void solve(int nod)
{
    viz[nod] = i;
    maxi[nod] = 0;
    int h, fmax = 0,ok = 0;
    ll x;
    for(h = 0; h < g[nod].size(); h++)
        if(viz[g[nod][h].first] != i)
    {
        ok = 1;
        tata[g[nod][h].first] = nod;
        solve(g[nod][h].first);
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
                s.push_back(x);
            }

    }
}

void park(int nod)
{
    viz[nod] = 1;
    maxi[nod] = 0;
    d[nod] = 0;
    int h;
    ll x;
    for(h = 0; h < g[nod].size(); h++)
        if(viz[g[nod][h].first]==0)
    {
        park(g[nod][h].first);
        x = maxi[g[nod][h].first]+g[nod][h].second;
        if(x > maxi[nod])
        {
            d[nod] = maxi[nod];
            maxi[nod] = x;
            fiu[nod] = g[nod][h].first;
        }
        else if(x>d[nod])d[nod] = x;
    }
}

void fly(int nod, ll su)
{
    viz[nod] = 2;
    rez[nod] = su;
    if(maxi[nod] > rez[nod])
        rez[nod] = maxi[nod];

    int h;
    ll x;
    for(h = 0; h < g[nod].size(); h++)
        if(viz[g[nod][h].first] != 2)
        {
            if(fiu[nod]==g[nod][h].first)x = d[nod];
            else x = maxi[nod];
            if(nod!=1)
                if(su > x) x = su;
            fly(g[nod][h].first,x+g[nod][h].second);
        }
}

void zbang()
{
    park(1);
    fly(1,maxi[1]);
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
    if(k==1) zbang();
    else{
    for(i = 1; i <= n; i++)
    {
        sol = 0;
        tata[i] = 0;
        solve(i);
        s.push_back(maxi[i]);
        sort(s.begin(),s.end());
        m = s.size();
        for(j = m-1; j >= m-k; j--)
            sol = sol +s[j];

        w << sol << "\n";
        s.clear();
    }
    }
    return 0;
}
