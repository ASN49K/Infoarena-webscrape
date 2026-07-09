#include <bits/stdc++.h>

using namespace std;

ifstream f("paths.in");
ofstream g("paths.out");

unsigned short n,copiebro,k,ct,tata[2005];
int costtata[2005];
long long dp[2005],suma;
vector<pair<unsigned short,int>>vecini[2005];

void dfs(unsigned short nod,unsigned short rad)
{
    long long maxim=0;
    tata[nod]=rad;
    unsigned short nr=0;
    for(unsigned short i=0; i<vecini[nod].size(); i++)
    {
        unsigned short x=vecini[nod][i].first;
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

void solve(unsigned short radacina)
{
    k=copiebro;
    for(unsigned short i=1; i<=n; i++) dp[i]=costtata[i]=0;
    ct=0;
    suma=0;
    dfs(radacina,0);

    if(ct<=k)
    {
        g<<suma<<'\n';
        return;
    }

    priority_queue< pair<long long,unsigned short> >perechi;
    perechi.push({dp[radacina],radacina});

    long long ans=0;

    while(k!=0)
    {
        k--;
        pair<long long,unsigned short> pp=perechi.top();
        perechi.pop();
        ans+=pp.first;

        ///dfs
        unsigned short nod=pp.second;
        while(nod!=0)
        {
            unsigned short nxt=0;
            for(unsigned short i=0; i<vecini[nod].size(); i++)
            {
                unsigned short x=vecini[nod][i].first;
                if(x==tata[nod]) continue;

                if(nxt==0&&dp[x]+costtata[nod]==dp[nod]) nxt=x;
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
    for(unsigned short i=1; i<n; i++)
    {
        unsigned short x,y;
        long long z;
        f>>x>>y>>z;
        vecini[x].push_back({y,z});
        vecini[y].push_back({x,z});
    }

    for(unsigned short i=1; i<=n; i++){
        solve(i);
    }
}
