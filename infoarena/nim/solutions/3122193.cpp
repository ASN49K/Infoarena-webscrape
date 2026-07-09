#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ar array
#define vt vector
#define pq priority_queue
#define pu push
#define pub push_back
#define em emplace
#define emb emplace_back
#define mt make_tuple

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define allp(x, l, r) x.begin() + l, x.begin() + r
#define len(x) (int)x.size()
#define uniq(x) unique(all(x)), x.end()

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

template <class T, size_t N>
void re(array <T, N>& x);
template <class T> 
void re(vt <T>& x);

template <class T> 
void re(T& x) {
    cin >> x;
}

template <class T, class... M> 
void re(T& x, M&... args) {
    re(x); re(args...);
}

template <class T> 
void re(vt <T>& x) {
    for(auto& it : x)
        re(it);
}

template <class T, size_t N>
void re(array <T, N>& x) {
    for(auto& it : x)
        re(it);
}

template <class T, size_t N>
void wr(array <T, N> x);
template <class T> 
void wr(vt <T> x);

template <class T> 
void wr(T x) {
    cout << x;
}

template <class T, class ...M>  void wr(T x, M... args) {
    wr(x), wr(args...);
}

template <class T> 
void wr(vt <T> x) {
    for(auto it : x)
        wr(it, ' ');
}

template <class T, size_t N>
void wr(array <T, N> x) {
    for(auto it : x)
        wr(it, ' ');
}

template<class T, class... M>
auto mvt(size_t n, M&&... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, mvt<T>(args...));
}

void set_fixed(int p = 0) {
    cout << fixed << setprecision(p);
}

void set_scientific() {
    cout << scientific;
}

inline void Open(const string Name) {
    #ifndef ONLINE_JUDGE
        (void)!freopen((Name + ".in").c_str(), "r", stdin);
        (void)!freopen((Name + ".out").c_str(), "w", stdout);
    #endif
}

void solve() {
    int n; re(n);
    vt <int> v(n); re(v);

    int xor_s = 0;
    for (int i = 0; i < n; ++i) {
        xor_s ^= v[i];
    }

    if (xor_s > 0) {
        wr("DA\n");
        return;
    }

    wr("NU\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //Open("");

    int t; re(t);
    for(;t;t--) {
        solve();
    }
    
    return 0;
}