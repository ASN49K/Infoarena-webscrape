#include <bits/stdc++.h>
//#define int long long
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
using namespace std;
const ll N=2000006, INF=1e18, P=998244353;

ll n, k, f[N], Ans[N], max_sum;
vector <il> v[N];     //graph
vector <li> V[N];     //onion_set (result in V[0])
pair<li, li> maxs[N]; //{subtree_max1, subtree_max2}
ll m[N];              //uptree_max_val
pii mx[N];            //{subtree_max_id, uptree_max_id}
set<li> s[2];         //{s[0] - Ans, s[1] - set \ Ans}
ll mp[N];             //useful_dist

void zaza(vector<li> &x, vector<li> &y, int c){
    y.back().F+=c;
    if(y.size()>x.size()){ swap(x, y); }
    if(x.back()>y.back()){ swap(x.back(), y.back()); }
    for (auto i:y)x.pb(i);
}
void set_onion(int x){
    V[x].pb({0, x});
    f[x]^=1;
    for (auto [y,c]:v[x]){
        if(f[y]==f[0])continue;
        set_onion(y);
        zaza(V[x], V[y], c);
    }
}
void merj(auto &a, auto b, int c){
    auto &[amx1, amx2]=a;
    auto [bmx1, bmx2]=b;
    bmx1.F+=c;
    bmx2.F+=c;
    if(bmx1>amx1)swap(amx1, bmx1);
    if(bmx1>amx2)swap(amx2, bmx1);
    if(bmx2>amx2)swap(bmx2, amx2);
}
void find_maxs(int x){
    f[x]^=1;
    maxs[x]={{0, x}, {-1, 0}};
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
void du(int x, int y, int c, int o=0){
    auto [d,u]=mx[y];
    if(o)swap(d, u);
    li D={mp[d], d}, U={mp[u], u};
    ll &distd=D.F;
    ll &distu=U.F;
    //cout<<"_ "<<y<<": "<<d<<"_"<<distd<<" "<<u<<"_"<<distu<<endl;
    if(U<(*s[0].begin())){
        s[1].erase(U);
        distu+=c;mp[u]+=c;
        s[0].insert(U);max_sum+=distu;
        auto it=s[0].begin();
        s[1].insert(*it);
        max_sum-=(*it).F;
        s[0].erase(it);
    }else{
        s[0].erase(U);max_sum-=distu;
        distu+=c;mp[u]+=c;
        s[0].insert(U);max_sum+=distu;
    }
    if(D<(*s[0].begin())){
        s[1].erase(D);
        distd-=c;mp[d]-=c;
        s[1].insert(D);
    }else{
        s[0].erase(D);max_sum-=distd;
        distd-=c;mp[d]-=c;
        s[1].insert(D);
        auto it=s[1].end();it--;
        s[0].insert(*it);
        max_sum+=(*it).F;
        s[1].erase(it);
    }
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
        du(x, y, c);
        dfs(y);
        du(x, y, c, 1);
    }
}
void build_set(){
    for (auto [dist,y]:V[0]){
        s[0].insert({dist, y});
        mp[y]=dist;
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
}
main(){
    input();
    set_onion(0);
    find_maxs(0);
    find_maxs2(0);
    build_set();
    dfs(0);
    output();
}
