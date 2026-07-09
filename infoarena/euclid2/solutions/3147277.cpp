#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define pf first
#define ps second
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#pragma GCC optimize("O3")

void pbinfo(string filename) {
  // #pragma message("be careful, freopen may be wrong")
    freopen((filename + ".in").c_str(), "r", stdin);
    freopen((filename + ".out").c_str(), "w", stdout);
}

int t, a, b;

void solve()
{
    
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &a, &b); 
        printf("%d\n", __gcd(a, b));
    }
}

int32_t main ()
{
    fastIO
    pbinfo("euclid2");
    solve();
    
    return 0;   
}

