#include <bits/stdc++.h>

using namespace std;
ifstream fin("paths.in");
ofstream fout("paths.out");
const int Nmax=1e5+5;
vector<pair<int,int>> g[Nmax];
int path[Nmax];
multiset<int> s;
void dfs(int nod,int pr)
{
    int best=-1;
    for(auto [u,c]:g[nod])
    {
        if(u!=pr)
        {
            dfs(u,nod);
            if(path[u]+c>path[nod])
            {
                path[nod]=path[u]+c;
                best=u;
            }
        }
    }
    if(best==-1)return;
    if(nod==pr)
    {
        for(auto [u,c]:g[nod])
        {
            if(u!=pr)
            {
                ///cout<<nod<<' '<<u<<' '<<path[u]+c<<'\n';
                s.insert(path[u]+c);
            }
        }
    }
    else
    {
        for(auto [u,c]:g[nod])
        {
            if(u!=pr && u!=best)
            {
                ///cout<<nod<<' '<<u<<' '<<path[u]+c<<'\n';
                s.insert(path[u]+c);
            }
        }
    }
}
void solve(int root,int k,int n)
{
    s.clear();
    for(int i=1;i<=n;i++) path[i]=0;
    dfs(root,root);
    int sum=0,cnt=1;
    for(auto it=s.rbegin();it!=s.rend() && cnt<=k;it++,cnt++)
    {
        sum+=(*it);
    }
    fout<<sum<<'\n';
}
int main()
{
    int n,k;
    fin>>n>>k;
    for(int i=1; i<n; i++)
    {
        int x,y,c;
        fin>>x>>y>>c;
        g[x].push_back({y,c});
        g[y].push_back({x,c});
    }
    for(int i=1; i<=n; i++)
    {
        solve(i,k,n);
    }
    return 0;
}
