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

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define allp(x, l, r) x.begin() + l, x.begin() + r
#define len(x) (int)x.size()

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


inline void Open(const string Name) {
    #ifndef ONLINE_JUDGE
        (void)!freopen((Name + ".in").c_str(), "r", stdin);
        (void)!freopen((Name + ".out").c_str(), "w", stdout);
    #endif
}

void solve() {
    /* standard algorithm */
    function <void(int, int)> dfs;
    int n, m; re(n, m);
    vt <int> a(n), b(m); re(a, b);

    /* DP :-
        i := number of elements form the first array
        j := number of elements from the second array
        dp[i][j] := maximum number of matches with i elements from the first array
                    and j elements from the second array
    */
    vt <vt <int>> dp(n + 1, vt <int>(m + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                // if both are equal we have a match
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // if none are equal we select the biggest matched we have so far
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

    wr(dp[n][m], '\n');

    // traceback to find the optimal subset
    dfs = [&](int i, int j) {
        if(i == 0 and j == 0)
            return;

        if (dp[i][j] == dp[i - 1][j - 1] + 1) {
            dfs(i - 1, j - 1);
            wr(a[i - 1], ' ');
            return;
        }

        if (dp[i][j] == dp[i - 1][j]) {
            dfs(i - 1, j);
            return;
        }

        dfs(i, j - 1);
    };

    dfs(n, m);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Open("cmlsc");

    int t = 1;
    for(;t;t--) {
        solve();
    }
    
    return 0;
}