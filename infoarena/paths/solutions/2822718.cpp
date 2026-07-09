#include <bits/stdc++.h>
//#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
/*
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/

#define ll long long
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define li pair<ll, int>
#define il pair<int, ll>
#define FF F.F
#define FS F.S
#define SF S.F
#define SS S.S
#define pb push_back
#define Mp make_pair
using namespace std;
const ll N=100006, INF=1e18;

ll n, k, f[N], Ans[N], max_sum;
vector <il> v[N];     //graph
vector <li> V;        //onion_set (result in V[0])
pair<li, li> maxs[N]; //{subtree_max1, subtree_max2}
ll m[N];              //uptree_max_val
pii mx[N];            //{subtree_max_id, uptree_max_id}
set<li> s[2];         //{s[0] - Ans, s[1] - set \ Ans}
li mp[N];             //{useful_dist, id}
li d[N];
li pa[N];
bool ff[N];

/*void zaza(vector<li> &x, vector<li> &y, int c){
    y.back().F+=c;
    if(y.size()>x.size()){ swap(x, y); }
    if(x.back()>y.back()){ swap(x.back(), y.back()); }
    copy(all(y), x.end());
    int sz1=x.size(), sz2=y.size();
    x.resize(sz1+sz2);
    copy(all(y), x.begin()+sz1);

    //for (auto i:y)x.pb(i);
}
void set_onion(int x){
    V[x].pb({0, x});
    f[x]^=1;
    for (auto [y,c]:v[x]){
        if(f[y]==f[0])continue;
        set_onion(y);
        zaza(V[x], V[y], c);
    }
}*/
void df(int x){
    f[x]^=1;
    for (auto [y,c]:v[x]){
        if(f[y]==f[0])continue;
        d[y]={d[x].F+c, y};
        pa[y]={c, x};
        df(y);
    }
}
void merj(auto &a, auto b, int c){
    auto &[amx1, amx2]=a;
    auto [bmx1, bmx2]=b;
    bmx1.F+=c;
    if(bmx1>amx1)swap(amx1, bmx1);
    if(bmx1>amx2)swap(amx2, bmx1);
    //if(bmx2>amx2)swap(bmx2, amx2);
}
void find_maxs(int x){
    f[x]^=1;
    maxs[x]={{0, x}, {-INF, 0}};
    for (auto [y,c]:v[x]){
        if(f[y]==f[0])continue;
        find_maxs(y);
        merj(maxs[x], maxs[y], c);
    }
    mx[x].F=maxs[x].FS;
}
void find_maxs2(int x){
    f[x]^=1;
    for (auto [y,c]:v[x]){
        if(f[y]==f[0])continue;
        auto &[d,u]=mx[y];
        u=maxs[x].FS;
        m[y]=maxs[x].FF+c;
        if(d==u){ u=maxs[x].SS; m[y]=maxs[x].SF+c; }
        if(m[y]<m[x]+c){ u=mx[x].S; m[y]=m[x]+c; }
        find_maxs2(y);
    }
}
void moove(bool i, bool j, li &p, ll c){
    max_sum+= -(!i)*p.F +(!j)*(p.F+c);
    s[i].erase(p);
    p.F+=c;
    s[j].insert(p);
}
void moove(bool i, bool j, li p){
    max_sum+= -(!i)*p.F + (!j)*p.F;
    s[i].erase(p);
    s[j].insert(p);
}
void du(int y, ll c, int o=0){
    auto [d,u]=mx[y];
    if(o)swap(d, u);
    auto &U=mp[u], &D=mp[d];
    ll &distd=mp[d].F;
    ll &distu=mp[u].F;
    //cout<<"_ "<<y<<": "<<d<<"_"<<distd<<" "<<u<<"_"<<distu<<endl;
    if(U>=(*s[0].begin())){ moove(0,0,U, c); }
    else{ moove(1,0,U, c); moove(0,1,*s[0].begin()); }
    if(D< (*s[0].begin())){ moove(1,1,D,-c); }
    else{ moove(0,1,D,-c); moove(1,0,*(--s[1].end())); }
}
void dfs(int x){
    //cout<<x<<":"<<endl;
    //for (auto [i, j]:s[0])cout<<i<<"_"<<j<<" ";
    //cout<<endl;
    //for (auto [i, j]:s[1])cout<<i<<"_"<<j<<" ";
    //cout<<endl;
    //cout<<max_sum<<endl;
    f[x]^=1;
    Ans[x]=max_sum;
    for (auto [y,c]:v[x]){
        if(f[y]==f[0])continue;
        du(y, c);
        dfs(y);
        du(y, c, 1);
    }
}
void build_set(){
    for (auto [dist,y]:V){
        s[0].insert({dist, y});
        mp[y]={dist, y};
        max_sum+=dist;
        //cout<<y<<"_"<<dist<<endl;
    }
    while(s[0].size()!=k){
        s[1].insert(*s[0].begin());
        max_sum-=(*s[0].begin()).F;
        s[0].erase(s[0].begin());
    }
}
void input(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    freopen("paths.in", "r", stdin);
    freopen("paths.out", "w", stdout);
    cin>>n>>k;
    int x, y;
    ll c;
    for (int i=1; i<n; i++){
        cin>>x>>y>>c;
        x--;y--;
        v[x].pb({y, c});
        v[y].pb({x, c});
    }
}
void output(){
    for (int i=0; i<n; i++){ cout<<Ans[i]<<'\n'; }
    //for (int i=0; i<n; i++){
    //    cout<<mx[i].F<<" "<<mx[i].S<<" "
    //        <<maxs[i].FF<<" "<<maxs[i].FS<<" "
    //        <<maxs[i].SF<<" "<<maxs[i].SS<<" AAA\n";
    //}
}

main(){
    input();
    df(0);
    sort(d, d+n);
    V.resize(n);
    for (int i=n-1; i>=0; i--){
        //cout<<d[i].F<<"_"<<d[i].S<<" ";
        for (int x=d[i].S; !ff[x]; x=pa[x].S){
            ff[x]=1;
            V[d[i].S].F+=pa[x].F;
        }
        V[d[i].S].S=d[i].S;
    }
    //cout<<endl;
    //for (auto [x, y]:)
    //set_onion(0);
    find_maxs(0);
    find_maxs2(0);
    build_set();
    dfs(0);
    output();
}
