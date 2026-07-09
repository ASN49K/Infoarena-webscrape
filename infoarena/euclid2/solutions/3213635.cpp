#pragma GCC optimize ("03", "Ofast", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define INFILE "euclid2.in"
#define OUTFILE "euclid2.out"

typedef long long ll;

ll euclid(ll a, ll b){
    if(b == 0) return a;
    return euclid(b, a % b);
}

void solve(){

    ll a, b; cin >> a >> b;
    cout << euclid(a, b) << '\n';

}

int main(){
    ios_base::sync_with_stdio(false);
    freopen(INFILE, "r", stdin);
    freopen(OUTFILE, "w", stdout);
    cin.tie(0), cout.tie(0);
    int tests;
    cin >> tests;
    for(int i = 0; i < tests; ++i) solve();
    return 0;
}