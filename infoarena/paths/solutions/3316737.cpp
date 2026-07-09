#include <bits/stdc++.h>
#define int long long
using namespace std;
ifstream fin("paths.in");
ofstream fout("paths.out");
const int Nmax=1e5+5;
vector<pair<int,int>> g[Nmax];
int path[Nmax];
int k;
int ans[Nmax];
class SETK
{
private:
    multiset<int> top;
    multiset<int> bottom;
    int sum;
public:
    void add(int x)
    {
        if(top.size()<k)
        {
            top.insert(x);
            sum+=x;
            return;
        }
        int low=(*top.begin());
        if(x>low)
        {
            sum+=x-low;
            top.insert(x);
            bottom.insert(low);
            top.erase(top.find(low));
            return;
        }
        bottom.insert(x);
    }
    void del(int x)
    {
        if(!bottom.empty() && bottom.find(x)!=bottom.end())
        {
            bottom.erase(bottom.find(x));
            return;
        }
        sum-=x;
        top.erase(top.find(x));
        if(!bottom.empty())
        {
            int big=(*bottom.rbegin());
            bottom.erase(bottom.find(big));
            top.insert(big);
            sum+=big;
        }
    }
    int getsum()
    {
        return sum;
    }
};
SETK s;
multiset<int> fii[Nmax];
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
                s.add(path[u]+c);
                fii[nod].insert(path[u]+c);
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
                s.add(path[u]+c);
                fii[nod].insert(path[u]+c);
            }
        }
        fii[nod].insert(path[nod]);
    }
}

void dfs2(int nod,int pr)
{
    ans[nod]=s.getsum();
    for(auto [u,c]:g[nod])
    {
        if(u!=pr)
        {
            int ptu=path[u],ptn=path[nod];
            fii[nod].erase(fii[nod].find(path[u]+c));
            path[nod]=(*fii[nod].rbegin());
            s.del(path[nod]);
            s.del(path[u]+c);
            s.add(path[u]);
            s.add(path[nod]+c);
            path[u]=max(path[u],path[nod]+c);
            fii[u].insert(path[nod]+c);
            dfs2(u,nod);
            path[u]=ptu,fii[u].erase(fii[u].find(path[nod]+c));
            s.del(path[nod]+c),s.del(path[u]);
            s.add(path[u]+c),s.add(path[nod]);
            path[nod]=ptn;
            fii[nod].insert(path[u]+c);
        }
    }
}
signed main()
{
    int n;
    fin>>n>>k;
    for(int i=1; i<n; i++)
    {
        int x,y,c;
        fin>>x>>y>>c;
        g[x].push_back({y,c});
        g[y].push_back({x,c});
    }
    dfs(1,1);
    dfs2(1,1);
    for(int i=1;i<=n;i++) fout<<ans[i]<<'\n';
    return 0;
}
