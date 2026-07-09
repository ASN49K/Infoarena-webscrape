#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ld long double
#define fi first
#define se second
#define MP make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mod (ll) (1e9 + 7)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define all(v) v.begin(), v.end()
#define dvec(v) for(auto i: v) cout << i << " "; cout << '\n';
#define gcd(a,b) __gcd(a, b)
#define lcm(a,b) ((a)*((b)/gcd(a,b)))
#define darr(a,n) for(int i=0; i<n;i++) cout << a[i] << " "; cout << '\n';
#define what_is(x) cerr << #x << " : " << x << '\n';


int main() {
    fast;
    int t; cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << gcd(a,b) << endl;
    }
    

    return 0;
}
