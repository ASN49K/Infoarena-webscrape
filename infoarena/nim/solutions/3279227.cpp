#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INFILE "nim.in"
#define OUTFILE "nim.out"

void solve(){

    int n; cin >> n;
    int a; cin >> a;
    for(int i = 1; i < n; ++i){
        int aux; cin >> aux;
        a ^= aux;
    }

    if(a == 0) cout << "NU" << '\n';
    else cout << "DA" << '\n';

}

int main(){
    ios_base::sync_with_stdio(false);
    freopen(INFILE, "r", stdin);
    freopen(OUTFILE, "w", stdout);
    cin.tie(0), cout.tie();
    int tests; cin >> tests;
    while(tests--) solve();
    return 0;
}
