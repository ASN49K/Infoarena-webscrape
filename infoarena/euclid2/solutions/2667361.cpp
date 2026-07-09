//ssense
#include<bits/stdc++.h>
//#include "/Users/mihaiesanu/testlib.h"
#define startt ios_base::sync_with_stdio(false);cin.tie(0);
typedef unsigned long long ull;
typedef long long  ll;
using namespace std;
#define FOR(n) for(int i=0;i<n;i++)
#define vt vector
#define sz(a) (int)a.size()
#define MOD 1000000007
#define MOD2 998244353
#define MX 1000000000
#define NMAX 100005
#define MXL 1000000000000000000
#define PI 3.14159265
#define pb push_back
#define pf push_front
#define sc second
#define endl '\n'
#define fr first
#define int ll
#define ld long double

int gcd(int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--)
    {
        int a,b;
        cin >> a >> b;
        cout << gcd(a,b) << endl;
    }
}

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

