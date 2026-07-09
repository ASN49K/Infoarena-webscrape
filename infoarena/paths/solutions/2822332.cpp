#include <bits/stdc++.h>

using namespace std;

ifstream f("paths.in");
ofstream g("paths.out");

int n,copiebro,k,ct,tata[100005],costtata[100005];
long long dp[100005],suma;
vector<pair<int,int>>vecini[100005];

void dfs(int nod,int rad)
{
    long long maxim=0;
    tata[nod]=rad;
    int nr=0;
    for(int i=0; i<vecini[nod].size(); i++)
    {
        int x=vecini[nod][i].first;
        if(x==rad) continue;

        dp[x]=vecini[nod][i].second;
        dfs(x,nod);
        costtata[x]=vecini[nod][i].second;
        maxim=max(maxim,dp[x]);
        suma+=vecini[nod][i].second;
        nr++;
    }
    dp[nod]+=maxim;

    if(nr==0) ct++;
}

void solve(int radacina)
{
    k=copiebro;
    for(int i=1; i<=n; i++) dp[i]=costtata[i]=0;
    ct=0;
    suma=0;
    dfs(radacina,0);

    if(ct<=k)
    {
        g<<suma<<'\n';
        return;
    }

    set< pair<int,int> > perechi;
    perechi.insert({dp[radacina],radacina});

    long long ans=0;

    while(k!=0)
    {
        k--;
        pair<int,int> pp=*perechi.rbegin();
        perechi.erase(pp);
        ans+=pp.first;

        ///dfs
        int nod=pp.second;

        int cnt=1;
        while(cnt>0)
        {
            cnt=0;
            int nxt=-1;
            for(int i=0; i<vecini[nod].size(); i++)
            {
                int x=vecini[nod][i].first;
                if(x==tata[nod]) continue;

                cnt++;
                if(nxt==-1&&dp[x]+costtata[nod]==dp[nod]) nxt=x;
                else perechi.insert({dp[x],x});
            }
            nod=nxt;
        }
    }
    g<<ans<<'\n';
}

int main()
{
    f>>n>>k;
    copiebro=k;
    for(int i=1; i<n; i++)
    {
        int x,y,z;
        f>>x>>y>>z;
        vecini[x].push_back({y,z});
        vecini[y].push_back({x,z});
    }

    for(int i=1; i<=n; i++)
    {
        solve(i);
    }
}
