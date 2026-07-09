#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fi first
#define sc second
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
template<typename type>
using ordered_set = tree<type, null_type, less<type>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 2e9;
const int dl[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};
const int ddl[] = {-1, -1, -1, 0, 1, 1, 1, 0}, ddc[] = {-1, 0, 1, 1, 1, 0, -1, -1};

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
int rng(int lo = 1, int hi = INT_MAX) {
    uniform_int_distribution<int> rnd(lo, hi);
    return rnd(gen);
}

struct mint {
    int val;
    mint(int32_t x = 0) {
        val = x % mod;
    }
    mint(long long x) {
        val = x % mod;
    }
    mint operator+(mint x) {
        return val + x.val;
    }
    mint operator-(mint x) {
        return val - x.val + mod;
    }
    mint operator*(mint x) {
        return 1LL * val * x.val;
    }
    void operator+=(mint x) {
        val = (*this + x).val;
    }
    void operator-=(mint x) {
        val = (*this - x).val;
    }
    void operator*=(mint x) {
        val = (*this * x).val;
    }
    friend auto operator>>(istream& in, mint &x) -> istream& {
        in >> x.val;
        x.val %= mod;
        return in;
    }
    friend auto operator<<(ostream& out, mint const &x) -> ostream& {
        out << x.val;
        return out;
    }
};

int n, m, s, t;

struct MCMF {
    struct edge {
        int nxt, cap, cost;
    };

    int n;
    vector<int> dst, po, pre;
    vector<vector<int>> g;
    vector<edge> e;

    MCMF(int x) {
        n = x;
        e.clear();
        g.resize(n + 5);
        dst.resize(n + 5);
        po.resize(n + 5);
        pre.resize(n + 5);
    }
    void addEdge(int x, int y, int cap, int cost) {
        g[x].pb(e.size());
        e.pb({y, cap, cost});
        g[y].pb(e.size());
        e.pb({x, 0, -cost});
    }
    bool dijk(int s, int t) {
        dst.assign(n + 5, inf);
        pre.assign(n + 5, -1);

        dst[s] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> que;
        que.push({0, s});
        while(!que.empty()) {
            auto [d, nod] = que.top();
            que.pop();
            if(d != dst[nod])
                continue;
            
            for(auto i : g[nod]) {
                auto [nxt, cap, cost] = e[i];
                if(cap && dst[nxt] > dst[nod] + po[nod] - po[nxt] + cost) {
                    dst[nxt] = dst[nod] + po[nod] - po[nxt] + cost;
                    pre[nxt] = i;
                    que.push({dst[nxt], nxt});
                }
            }
        }

        return dst[t] < inf;
    }
    pii mcmf(int s, int t) {
        int ansflow = 0, anscost = 0;
        po.assign(n + 5, 0);
        while(dijk(s, t)) {
            for(int i=1; i<=n; i++)
                po[i] += dst[i];
            int aug = inf;
            for(int x=t; x!=s; x=e[pre[x]^1].nxt)
                aug = min(aug, e[pre[x]].cap);
            for(int x=t; x!=s; x=e[pre[x]^1].nxt) {
                e[pre[x]].cap -= aug;
                e[pre[x]^1].cap += aug;
            }

            ansflow += aug;
            anscost += po[t] * aug;
        }

        return {ansflow, anscost};
    }
};

int32_t main()
{
    freopen("fmcm.in", "r", stdin);
    freopen("fmcm.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(0);
    
    cin >> n >> m >> s >> t;
    MCMF ew(n);
    for(int i=1; i<=m; i++) {
        int x, y, c, z;
        cin >> x >> y >> c >> z;
        ew.addEdge(x, y, c, z);
    }

    cout << ew.mcmf(s, t).sc;
    return 0;
}