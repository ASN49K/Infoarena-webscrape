/**
 * Author: Andu Scheusan (not_andu)
 * Created: 08.11.2023 18:31:42
*/

#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

#define INFILE "nim.in"
#define OUTFILE "nim.out"

#define all(x) (x).begin(), (x).end()
#define MP make_pair
#define F first
#define S second

typedef long long ll;

void solve(){

    int n, ans = 0; cin >> n;

    for(int i = 1; i <= n; ++i){
        int aux; cin >> aux; ans ^= aux;
    }

    if(ans == 0){
        cout << "NU" << '\n';
    }
    else{
        cout << "DA" << '\n';
    }

}

int main(){
    
    ios_base::sync_with_stdio(false);

    freopen(INFILE, "r", stdin);
    freopen(OUTFILE, "w", stdout);

    cin.tie(nullptr);
    cout.tie(nullptr);

    int tests; cin >> tests;
    for(int i = 0; i < tests; ++i) solve();

    return 0;
}