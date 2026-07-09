#include <bits/stdc++.h>

#define f first
#define s second
#define vec vector
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pw(x) (1LL<<(x))
#define sz(x) (int)(x).size()
#define fast_lzo ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//#pragma GCC target("avx,avx2,tune=native")
#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,int> pli;
typedef pair<int,int> pii;
const int N=1e5+1;
vec<pii> g[N];
pli dp[N];
set<pli> fi,si;
int k;
ll sm=0;
ll ans[N];
ll vl[N];
void balance(){
    while(sz(fi) && sz(si)){
        auto x=*fi.begin(),y=*si.rbegin();
        if(x>y)
            break;
        fi.erase(x);si.erase(y);
        sm-=x.f;sm+=y.f;
        fi.insert(y);si.insert(x);
    }
    while(sz(fi)>k){
        auto x=*fi.begin();
        sm-=x.f;
        fi.erase(x);si.insert(x);
    }
    while(sz(fi)<k && sz(si)){
        auto x=*si.rbegin();
        sm+=x.f;
        si.erase(x);fi.insert(x);
    }
}
void add(pli x){
    si.insert(x);
    balance();
}
void del(pli x){
    if(fi.count(x)) fi.erase(x),sm-=x.f;
    else si.erase(x);
    balance();
}
void dfs(int v,int p){
    dp[v]={0,v};
//    add({0,v});
    for(auto &z : g[v]){
        if(z.f==p)
            continue;
        dfs(z.f,v);
        dp[v]=max(dp[v],{dp[z.f].f+z.s,dp[z.f].s});
        vl[dp[z.f].s]=dp[z.f].f+z.s;
    }
}
void dfs1(int v,pli from,int p){
    vec<pli>pref,suf;
    ans[v]=sm;
    pli me=from;
    me=max(me,{(ll)0,v});
    vec<pli> go;
    for(auto &z : g[v]){
        if(z.f!=p)
            go.pb(z);
    }
    int m=sz(go);
    pref.resize(m);
    for(int i=0;i<m;i++){
        pref[i]=me;
        me=max(me,{dp[go[i].f].f+go[i].s,dp[go[i].f].s});
    }
    suf=pref;
    me=from;
    for(int i=m-1;i>=0;i--){
        suf[i]=me;
        me=max(me,{dp[go[i].f].f+go[i].s,dp[go[i].f].s});
    }
    for(int i=0;i<m;i++){
        pli be=max(pref[i],suf[i]);
        pli blya=dp[go[i].f];blya.f+=go[i].s;

        del(blya);del(be);

        blya.f-=go[i].s;be.f+=go[i].s;
        add(blya);add(be);
        ///
        dfs1(go[i].f,be,v);
        ///
        del(blya);del(be);

        blya.f+=go[i].s;be.f-=go[i].s;
        add(blya);add(be);
    }
}
signed main(){
    fast_lzo;
    ifstream cin("paths.in");
    ofstream cout("paths.out");
    int n;
//    n=100'000;k=n/2;
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int v,u,x;
        cin>>v>>u>>x;--v;--u;
        g[v].pb({u,x});
        g[u].pb({v,x});

    }
    dfs(0,0);
//    vec<pli> vt;
//    for(int i=0;i<n;i++)
//        vt.pb({vl[i],i});
//    sort(rall(vt));
//    for(auto &z : vt){
//        if(sz(fi)>=k) si.insert(z);
//        else fi.insert(z),sm+=z.f;
//    }
    for(int i=0;i<n;i++)
        add({vl[i],i});
//    for(auto &z : fi)
//        cout<<z.f<<' '<<z.s<<endl;
//    cout<<endl;
//    for(auto z : si)
//        cout<<z.f<<' '<<z.s<<endl;

    dfs1(0,{0,0},-1);
    for(int i=0;i<n;i++)
        cout<<ans[i]<<'\n';
    return 0;
}
/*

*/
