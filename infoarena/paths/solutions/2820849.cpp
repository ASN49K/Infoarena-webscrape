#include<bits/stdc++.h>
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
    int l,r,m;
    pl mx={-1e18,-1e18};

    ll prop=0;

    seg *lp=0,*rp=0;

    seg (){}
    seg(int l,int r):l(l),r(r),m((l+r)/2){
        if(l+1<r){
            lp=new seg(l,m);
            rp=new seg(m,r);
        }
    }

    void set_who(int i,int v){
        if(l+1==r){
            mx.second=v;
            return;
        }
        if(i<m)
            lp->set_who(i,v);
        else
            rp->set_who(i,v);
    }
    void add(ll x){
        if(mx.first==-1e18)
            mx.first=0;
        mx.first+=x;
        prop+=x;
    }
    void push(){
        lp->add(prop);
        rp->add(prop);
        prop=0;
    }

    void upd(ll a,ll b,ll x){

        if(b<=l || r<=a)
            return ;
        else if(a<=l && r<=b) {
            add(x);
            return;
        }
        push();
        lp->upd(a,b,x);
        rp->upd(a,b,x);

        mx=max(lp->mx,rp->mx);
    }
    pl qur(ll a,ll b){
        if(b<=l || r<=a)
            return{-1e18,-1e18};
        else if(a<=l && r<=b)
            return mx;
        push();
        return max(lp->qur(a,b),rp->qur(a,b));
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
        cur=up[cur];
    }
    return ans;
}
ll calc(ll s){

    timer=0;
    w_up.assign(n+1,0);
    ST=seg(0,n+2);
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

    usaco("paths");
    cin >> n >> k;
    g.resize(n+1);
    for(int i=0; i<n-1; i++){
        ll u,v,w;
        cin >> u >> v >> w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    tin.resize(n+1),tout.resize(n+1),up.resize(n+1),w_up.resize(n+1);

    for(int i=1; i<=n; i++)
        cout << calc(i) << "\n";
}