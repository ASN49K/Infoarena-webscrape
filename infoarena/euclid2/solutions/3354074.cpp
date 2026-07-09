#include <bits/stdc++.h>
#include <cstdint>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define pb push_back
// #define int long long
#define cin fin
#define cout fout
#define NMAX 2000005
#define nl '\n'
#define pii pair<int,int>
#define tpl tuple<int,int,int>
#define INF 1e9
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
const int MOD=998244353;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*
 *=======================DEMONSTRATION====================



 *========================================================
 */

void solve() {
    int a,b;
    cin>>a>>b;

    while (b) {
        a = b;
        b = a % b;
    }

    cout<<a<<nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    cin>>t;
    while (t--) {
        solve();
    }

    return 0;
}