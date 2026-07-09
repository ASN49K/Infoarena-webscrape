#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define all(x) x.begin(), x.end()
//memset(arr, -1, sizeof(arr))

const int m = 1e5 + 7;
/*
void solve(){

}
*/

int GCD(int a, int b){
    if(b == 0) return a;
    return GCD(b, a%b);
}

int main(){
    //ios::sync_with_stdio(0);    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //int t;  cin >> t;   while(t--)
    //solve();
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    ll t; cin >> t; while(t--){
        ll a, b;
        cin >> a >> b;
        //int gcd = GCD(a, b);
        cout << __gcd(a, b) << endl;
    }

    return 0;
}
