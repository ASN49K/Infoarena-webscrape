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

int32_t main(){
    startt
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int a,b;
        cin >> a >> b;
        cout << __gcd(a,b) << endl;
    }
}

