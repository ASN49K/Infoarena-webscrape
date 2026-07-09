#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#define ll long long
#define N 100003
using namespace std;
ifstream f("paths.in");
ofstream w("paths.out");
int n,i,k,x,y,j;
int viz[N], tata[N];
ll maxi[N], sol, c;
vector< pair<int,int> > g[N];
multiset<ll> s;
multiset<ll>::iterator it;

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
                s.insert(-x);
            }

    }
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
    for(i = 1; i <= n; i++)
    {
        sol = 0;
        tata[i] = 0;
        solve(i);
        s.insert(-maxi[i]);
        j = 1;
        for(it = s.begin(); it != s.end(); it++)
        if(j <= k)
        {
            sol = sol - (*it);
            j++;
        }
        w << sol << "\n";
       // for(it = s.begin(); it != s.end(); it++)
         //   cout << -(*it) << " ";
        //cout << "\n";
        s.clear();
    }
    return 0;
}
