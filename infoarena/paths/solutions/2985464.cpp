#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <stdio.h>
#include <bitset>
 #include <cstdint>
#include <cassert>
#include <functional>
#include <complex>

using namespace std;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define ld long double
 
const ll maxn = 1e5 + 10, maxm = 3e5 + 1;
const ll mod = 1e9 + 7, cmod = 998244353, inf = 1e9, blcok = 400, p2 = 31;
const ld eps = 1e-9;

ll rng(){
    return (((ll)rand() << 15) + rand());
}
struct node{
    int sz;
    ll sum;
    ll key, prior, kol;
    node *l, *r;
    node(int x){
        key = x, prior = rng(), kol = 1;
        sum = x; sz = 1;
        l = r = nullptr;
    }
};
struct treap{
    int getsz(node *v){
        return (v == nullptr ? 0 : v->sz);
    }
    int getsum(node *v){
        return (v == nullptr ? 0 : v->sum);
    }
    void pull(node *v){
        v->sum = getsum(v->l) + getsum(v->r) + v->kol * v->key;
        v->sz = getsz(v->l) + getsz(v->r) + v->kol;
    }
    pair<node*, node*> split(node* &v, int x){
        if (v == nullptr)
            return mp(nullptr, nullptr);
        if (v->key < x){
            pair<node*, node*> splitted = split(v->r, x);
            v->r = splitted.f;
            pull(v);
            return mp(v, splitted.s);
        }
        else{
            pair<node*, node*> splitted = split(v->l, x);
            v->l = splitted.s;
            pull(v);
            return mp(splitted.f, v);
        }
    }
    node* merge(node *l, node *r){
        if (l == nullptr || r == nullptr)
            return (l ? l : r);
        if (l->prior > r->prior){
            l->r = merge(l->r, r);
            pull(l);
            return l;
        }
        else{
            r->l = merge(l, r->l);
            pull(r);
            return r;
        }
    }
    ll get(node* &v, ll k){
        if (k == 0)
            return 0;
       /* cout << v->key << " " << v->kol << '\n';
        cout << v->sz << '\n';
        cout << getsz(v->l) << '\n';
        cout << getsum(v->l) << '\n';*///
        if (getsz(v->l) + v->kol <= k){
            return getsum(v->l) + v->kol * v->key + get(v->r, k - getsz(v->l) - v->kol);
        }
        else if (getsz(v->l) <= k){
           // cout << "kek\n";
           // cout << get
            //cout << (k - getsz(v->l)) * v->key << " " << v->key << '\n';;
            return getsum(v->l) + (k - getsz(v->l)) * v->key;
        }
        else{
            return get(v->l, k);
        }
    }
} t;

node *root;
int n, k, leafs;
ll dp[maxn], ans[maxn];
vector<pair<int, int>> g[maxn];
vector<ll> vec;
void add(ll med){
    pair<node*, node*> spl1 = t.split(root, med);
    pair<node*, node*> spl2 = t.split(spl1.s, med + 1);
    if (spl2.f != nullptr){
        spl2.f->kol += 1;
        spl2.f->sz += 1;
        spl2.f->sum += med;
    }
    else{
        spl2.f = new node(med);
    }
    root = t.merge(t.merge(spl1.f, spl2.f), spl2.s);
}
void del(ll med){
    pair<node*, node*> spl1 = t.split(root, med);
    pair<node*, node*> spl2 = t.split(spl1.s, med + 1);
    if (spl2.f != nullptr){
        spl2.f->kol -= 1;
        spl2.f->sz -= 1;
        spl2.f->sum -= med;
        if (spl2.f->kol == 0){
            spl2.f = nullptr;
        }
    }
    root = t.merge(t.merge(spl1.f, spl2.f), spl2.s);
}
void dfs(int v = 1, int p = 0){
    dp[v] = 0;
    for (auto to : g[v]){
        int go = to.f, w = to.s;
        if (go != p){
            dfs(go, v);
            dp[v] = max(dp[v], dp[go] + w);
        }
    }
    int is = 0;
    for (auto to : g[v]){
        int go = to.f, w = to.s;
        if (go != p){
            if (dp[v] != dp[go] + w || is){
                ll z = dp[go] + w;
                add(z);
            }
            else{
                is = 1;
            }
        }
    }
}
void dfs2(int v = 1, int p = 0, int type = 0){
    vector<ll> sadd, sdel;
    int is = 0;
    for (auto to : g[v]){
        int go = to.f, w = to.s;
        if (go != p){
            if (dp[v] != dp[go] + w || is){
                ll z = dp[go] + w;
                del(z);
                sadd.pb(z);
            }
            else{
                is = 1;
            }
        }
    }
   // cout << root->sum << '\n';
    for (auto to : g[v]){
        int go = to.f, w = to.s;
        dp[v] = max(dp[v], dp[go] + w);
    }
    is = 0;
    for (auto to : g[v]){
        int go = to.f, w = to.s;
        if (dp[v] != dp[go] + w || is){
            ll z = dp[go] + w;
            add(z);
            sdel.pb(z);
        }
        else{
            if (go == p && type == 1){
                ll z = dp[go];
                del(z);
               // cout << "kek\n";
                sadd.pb(z);
            }
            is = 1;
        }
    }
    int lakers = root->sz;
    ans[v] = dp[v] + root->sum - t.get(root, lakers - (k - 1));
    multiset<ll> setik;
    for (auto to : g[v]){
        int go = to.f, w = to.s;
        setik.insert(dp[go] + w);
    }
    for (auto to : g[v]){
        int go = to.f, w = to.s;
        if (go != p){
            ll prevdp = dp[v];
            ll z = dp[go] + w;
            int isdel = 0;
            if (*setik.rbegin() != z){
                del(z);
                isdel = 1;
            }
            setik.erase(setik.find(z));
            dp[v] = *setik.rbegin();
            dfs2(go, v, !isdel);
            setik.insert(z);
            if (isdel){
                add(z);
            }
            dp[v] = prevdp;
        }
    }
    for (auto it : sadd){
        add(it);
    }
    for (auto it : sdel){
        del(it);
    }
    dp[v] = -inf;
    for (auto to : g[v]){
        int go = to.s, w = to.s;
        if (go != p){
            dp[v] = max(dp[v], dp[go] + w);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("paths.in", "r", stdin);
    freopen("paths.out", "w", stdout);
    cin >> n >> k;
    ll allsum = 0;
    for (int u, v, c, i = 1; i < n; ++i){
        cin >> u >> v >> c;
        g[u].pb(mp(v, c));
        g[v].pb(mp(u, c));
        allsum += c;
    }
    for (int i = 1; i <= n; ++i){
        leafs += ((int)g[i].size() == 1);
    }
    if (leafs <= k){
        for (int i = 1; i <= n; ++i){
            cout << allsum << " ";
        }
        exit(0);
    }
    dfs();
    dfs2();
    cout << "ok\n";
    exit(0);
    for (int i = 1; i <= n; ++i){
        cout << ans[i] << "\n";
    }
}
/*
*/

