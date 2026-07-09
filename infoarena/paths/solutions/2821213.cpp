#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

//using namespace __gnu_pbds;
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int>vi;
typedef vector<vector<int>>vvi;
typedef vector<ll>vl;
typedef vector<vl> vvl;
typedef pair<int,int>pi;
typedef pair<ll,ll> pl;
typedef vector<pl> vpl;
typedef vector<ld> vld;
typedef pair<ld,ld> pld;
typedef vector<pi> vpi;

//typedef tree<ll, null_type, less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
template<typename T> ostream& operator<<(ostream& os, vector<T>& a){os<<"[";for(int i=0; i<ll(a.size()); i++){os << a[i] << ((i!=ll(a.size()-1)?" ":""));}os << "]\n"; return os;}

#define all(x) x.begin(),x.end()
#define YES out("YES")
#define NO out("NO")
#define out(x){cout << x << "\n"; return;}
#define GLHF ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define print(x){for(auto ait:x) cout << ait << " "; cout << "\n";}
#define pb push_back
#define umap unordered_map

template<typename T1, typename T2> istream& operator>>(istream& is, pair<T1, T2>& p){is >> p.first >> p.second;return is;}
template<typename T1, typename T2> ostream& operator<<(ostream& os, pair<T1, T2>& p){os <<"" << p.first << " " << p.second << ""; return os;}
void usaco(string taskname){
    string fin = taskname + ".in";
    string fout = taskname + ".out";
    const char* FIN = fin.c_str();
    const char* FOUT = fout.c_str();
    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);
}
template<typename T>
void read(vector<T>& v){
    int n=v.size();
    for(int i=0; i<n; i++)
        cin >> v[i];
}
template<typename T>
vector<T>UNQ(vector<T>a){
    vector<T>ans;
    for(T t:a)
        if(ans.empty() || t!=ans.back())
            ans.push_back(t);
    return ans;
}



void solve();
int main(){
    GLHF;
    int t=1;
    //cin >> t;
    while(t--)
        solve();
}

vector<vpl>g;
int n,k;

int timer=0;

vi tin,tout,up;
vl w_up;

struct seg{
    vpl t;
    vl lz;
    int sz=1;

    seg(){}
    seg(int n){
        while(sz<=2*n)
            sz*=2;
        t.resize(sz);
        lz.resize(sz);
        for(int i=sz/2; i<sz; i++)
            t[i].second=i-sz/2;
    }

    void clear(){
        for(int i=0; i<sz; i++){
            t[i].first=t[i].second=0;
            lz[i]=0;
        }
    }
    void set_who(int i,int v){
        t[i+sz/2].second=v;
    }
    void add(int x,ll v){
        t[x].first+=v;
        lz[x]+=v;
    }
    void push(int x){
        add(2*x,lz[x]);
        add(2*x+1,lz[x]);
        lz[x]=0;
    }

    void upd(int a,int b,int l,int r,int x,ll v){
        if(b<=l || r<=a)
            return;
        else if(a<=l && r<=b){
            add(x,v);
            return;
        }
        push(x);

        int m=(l+r)/2;
        upd(a,b,l,m,2*x,v);
        upd(a,b,m,r,2*x+1,v);

        t[x]=max(t[2*x],t[2*x+1]);
    }

    void upd(int a,int b,ll v){
        upd(a,b,0,sz/2,1,v);
    }

    pl qur(int a,int b,int l,int r,int x){
        if(b<=l || r<=a)
            return {-1,-1};
        else if(a<=l && r<=b)
            return t[x];
        push(x);
        int m=(l+r)/2;

        return max(
                qur(a,b,l,m,2*x),
                qur(a,b,m,r,2*x+1));
    }
    pl qur(int a,int b){
        return qur(a,b,0,sz/2,1);
    }
};

seg ST;
void dfs(int src,int par){
    tin[src]=++timer;
    up[src]=par;
    for(pl nbr:g[src])
        if(nbr.first!=par) {
            dfs(nbr.first, src);
            w_up[nbr.first]=nbr.second;
        }
    tout[src]=timer;
}



ll upd(ll s){

    pl mx=ST.qur(1,n+1);

    ll ans=mx.first;
    ll cur=mx.second;

    while(cur!=s){
        ST.upd(tin[cur],tout[cur]+1,-w_up[cur]);
        w_up[cur]=0;
        ll p=up[cur];
        up[cur]=s;
        cur=p;
    }
    return ans;
}
ll calc(ll s){

    timer=0;
    ST.clear();
    w_up.assign(n+1,0);
    dfs(s,-1);

    for(int i=1; i<=n; i++)
        ST.set_who(tin[i],i);
    for(int i=1; i<=n; i++)
        ST.upd(tin[i],tout[i]+1,w_up[i]);

    ll ans=0;

    for(int i=0; i<k; i++)
        ans+=upd(s);

    return ans;
}
void solve() {

    //usaco("paths");
    cin >> n >> k;
    g.resize(n+1);
    for(int i=0; i<n-1; i++){
        ll u,v,w;
        cin >> u >> v >> w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    tin.resize(n+1),tout.resize(n+1),up.resize(n+1),w_up.resize(n+1);

    ST=seg(n+2);

    for(int i=1; i<=n; i++)
        cout << calc(i) << "\n";
}