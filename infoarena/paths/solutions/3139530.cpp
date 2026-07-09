#include <bits/stdc++.h>

using namespace std;
ifstream fin("paths.in");
ofstream fout("paths.out");
typedef long long ll;
typedef pair<ll,ll> pll;
ll n,k;
vector<pll> muchii[100005];
ll par[100005],topar[100005];
ll dist[100005];
ll lin[100005],in[100005],out[100005];
bool use[100005];
ll timp;
pll arb[4*100005];
ll toprop[4*100005];
void dfs(int nod)
{
    timp++;
    in[nod]=timp;
    lin[timp]=nod;
    for(auto i:muchii[nod])
    {
        ll x=i.first;
        if(x!=par[nod])
        {
            par[x]=nod;
            topar[x]=i.second;
            dist[x]=dist[nod]+i.second;
            dfs(x);
        }
    }
    out[nod]=timp;
}
pll combine(pll a,pll b)
{
    if(a.first<b.first)
        a=b;
    return a;
}
void build(int nod,int st,int dr)
{
    toprop[nod]=0;
    if(st==dr)
    {
        arb[nod]={dist[lin[st]],st};
        return;
    }
    int mij=(st+dr)/2;
    build(nod*2,st,mij);
    build(nod*2+1,mij+1,dr);
    arb[nod]=combine(arb[nod*2],arb[nod*2+1]);
}
void prop(int nod)
{
    ll val=toprop[nod];
    arb[nod*2].first+=val;
    arb[nod*2+1].first+=val;
    toprop[nod*2]+=val;
    toprop[nod*2+1]+=val;
}
void update(int nod,int st,int dr,int a,int b,ll val)
{
    if(st!=dr)
        prop(nod);
    toprop[nod]=0;
    if(st>=a&&dr<=b)
    {
        arb[nod].first+=val;
        toprop[nod]+=val;
        return;
    }
    int mij=(st+dr)/2;
    if(a<=mij)
        update(nod*2,st,mij,a,b,val);
    if(b>mij)
        update(nod*2+1,mij+1,dr,a,b,val);
    arb[nod]=combine(arb[nod*2],arb[nod*2+1]);
}
void calc(int root)
{
    timp=0;
    for(int i=1;i<=n;i++)
    {
        par[i]=0;
        use[i]=0;
        dist[i]=0;
    }
    dist[root]=0;
    timp=0;
    dfs(root);
    ll ans=0;
    build(1,1,n);
    for(int z=1;z<=k;z++)
    {
        ll nod=lin[arb[1].second];
        ans+=arb[1].first;
        while(!use[nod]&&nod!=root)
        {
            use[nod]=1;
            update(1,1,n,in[nod],out[nod],-topar[nod]);
            nod=par[nod];
        }
    }
    fout<<ans<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    fin.tie(0);
    fin>>n>>k;
    for(int i=1;i<n;i++)
    {
        ll a,b,c;
        fin>>a>>b>>c;
        muchii[a].push_back({b,c});
        muchii[b].push_back({a,c});
    }
    for(int root=1;root<=n;root++)
        calc(root);
    return 0;
}
