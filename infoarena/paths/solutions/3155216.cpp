#include <bits/stdc++.h>
#define bug(a) std::cerr << "(" << #a << ": " << a << ")\n";
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long
using namespace std;
//RMI = range minimum informatic
const int inf=1e9;
#define int long long
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
    cin.close();
}
////////////////////////////
////   the algorithm    ////
////////////////////////////
void dfs(priority_queue<int>&q,int nod,int tt=-1)
{
    dp[nod]={inf,0};
    for(auto &c:g[nod])
    {
        if(c.nod!=tt)
        {
            dfs(q,c.nod,nod);
            dp[c.nod].cost+=c.cost;
            if(dp[nod].cost<dp[c.nod].cost)
            {
                dp[nod].cost=dp[c.nod].cost;
                dp[nod].nod=c.nod;
            }
        }
    }
    if(tt==-1)
    {
        dp[nod].nod=inf;
    }
    for(auto &c:g[nod])
    {
        if(c.nod!=tt && c.nod!=dp[nod].nod)
        {
            q.push(dp[c.nod].cost);
        }
    }
}
void solve()
{
    ofstream cout("paths.out");
    dp=vector<duo>(n);
    for(int _=0;_<n;_++)
    {
        priority_queue<int>q;
        dfs(q,_);
        i64 sum=0;
        for(int i=0;i<k && q.size();i++)
        {
            sum+=q.top();
            q.pop();
        }
        cout<<sum<<'\n';
    }
    cout.close();
}
/////////////////////////////
///////////the end///////////
/////////////////////////////
main()
{
    read();
    solve();
}
