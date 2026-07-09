#include <bits/stdc++.h>

using namespace std;

ifstream f("paths.in");
ofstream g("paths.out");

int n,copiebro,k,ct,tata[2005],costtata[2005];
long long dp[2005],suma;
vector<pair<int,int>>vecini[2005];

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
        cout<<suma<<'\n';
        return;
    }

    priority_queue< pair<long long,int> >perechi;
    perechi.push({dp[radacina],radacina});

    long long ans=0;

    while(k!=0)
    {
        k--;
        pair<long long,int> pp=perechi.top();
        perechi.pop();
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
                else perechi.push({dp[x],x});
            }
            nod=nxt;
        }
    }
    g<<ans<<'\n';
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    f.tie(nullptr);

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
