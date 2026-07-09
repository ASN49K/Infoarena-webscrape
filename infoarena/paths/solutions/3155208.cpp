#include <bits/stdc++.h>
#include <windows.h>
#define bug(a) std::cerr << "(" << #a << ": " << a << ")\n";
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long
using namespace std;
//RMI = range minimum informatic
const int inf=1e9;
struct duo
{
    int nod;
    i64 cost;
    bool operator <(const duo& b)const
    {
        if(cost==b.cost)
            return nod<b.nod;
        return cost>b.cost;
    }
};
int n,k;
vector<vector<duo>>g;
vector<duo>dp;
void read()
{
    ifstream cin("paths.in");
    cin>>n>>k;
    g=vector<vector<duo>>(n);
    for(int i=1,x,y,z;i<n;i++)
    {
        cin>>x>>y>>z;
        x--;
        y--;
        g[x].pb({y,z});
        g[y].pb({x,z});
    }
}
////////////////////////////
////   the algorithm    ////
////////////////////////////
void dfs(int nod,int tt=-1)
{
    dp[nod]={inf+nod,0};
    for(auto &c:g[nod])
    {
        if(c.nod!=tt)
        {
            dfs(c.nod,nod);
            dp[c.nod].cost+=c.cost;
            if(dp[nod].cost<dp[c.nod].cost)
            {
                dp[nod].cost=dp[c.nod].cost;
                dp[nod].nod=c.nod;
            }
        }
    }
}
void solve()
{
    ofstream cout("paths.out");
    dp=vector<duo>(n);
    for(int _=0;_<n;_++)
    {
        dfs(_);
        set<duo>mp;
        for(int i=0;i<n;i++)
        {
            if(i!=_)
            {
                mp.insert(dp[i]);
            }
        }
        i64 rez=0;
        for(int i=0;i<k && mp.size();i++)
        {
            auto v=mp.begin();
            rez+=v->cost;
            mp.erase(v);
            for(int j=v->nod;j<inf;j=dp[j].nod)
            {
                mp.erase(dp[j]);
            }
        }
        cout<<rez<<'\n';
    }
}
/////////////////////////////
///////////the end///////////
/////////////////////////////
main()
{
    read();
    solve();
}
