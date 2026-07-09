/**
 * author:  xdaruis
 * created: 11.01.2024 01:07:41
 * https://www.infoarena.ro/problema/euclid2
**/
// #pragma comment(linker, "/stack:200000000")
// #pragma comment(linker, "/stack:256000000")
#pragma GCC optimize("O3")
// #pragma GCC target ("avx2")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;
using lld = long double;
constexpr int md = 1e9 + 7;
constexpr int md1 = 998244353;
constexpr ll inf = 1e18;
const vector<pair<int, int>> dir8{{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1 , 0}, {1, -1}, {0, -1}, {-1, -1}};
const vector<pair<int, int>> dir4{{-1, 0}, {0, 1}, {1 , 0}, {0, -1}};

#define all(x) (x).begin(), (x).end()
template <class T> istream &operator>>(istream &is, vector<T> &v) { for (auto &x : v) is >> x; return is; }
template <class T> ostream &operator<<(ostream &os, const vector<T> &v) { auto sep = ""; for (auto &x : v) os << exchange(sep, " ") << x; return os; }

#ifdef LOCAL
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << '\n'; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define deb(...) cerr << #__VA_ARGS__ << "->", dbg_out(__VA_ARGS__);
#define START auto start_time = chrono::high_resolution_clock::now();
#define END cerr << "Execution Time: " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count() << " ms\n";
#define ROAD_TO_RED cerr << "Solved: " << t << '\n';
#else
#define deb(...)
#define START
#define END
#define ROAD_TO_RED
#endif

// #define double lld
// #define int ll
// #define vi vector<ll>


int euclid(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int a, b;
    cin >> a >> b;
    cout << euclid(a, b);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int T = 1;
    cin >> T;
    deb(T);
    for (int t = 1; t <= T; ++t) {
        solve();
        cout << '\n';
        ROAD_TO_RED
    }
    return 0;
}