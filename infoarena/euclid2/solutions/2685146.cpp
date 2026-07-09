#include <bits/stdc++.h>
//#pragma GCC optimize ("03")
#define FastIO ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)
#define FILES freopen("euclid2.in" , "r" , stdin) , freopen("euclid2.out" , "w" , stdout)
#define ll long long
#define ull unsigned long long
#define ld long double
#define eb emplace_back
#define pb push_back
#define qwerty1 first
#define qwerty2 second
#define qwerty3 -> first
#define qwerty4 -> second
#define umap unordered_map
#define uset unordered_set
#define pii pair < ll , ll >
#define pq priority_queue
#define dbg(x) cerr << #x << ": " << x << '\n'

namespace FastRead
{
    char buff[5000];ll lg = 0 , p = 0;
    char nc()
    {
        if(lg == p){lg = fread(buff , 1 , 5000 , stdin);p = 0;if(!lg) return EOF;}
        return buff[p++];
    }
    template<class T>void read(T&x)
    {
        T sgn = 1; char c;while(!isdigit(c = nc()))if(c == '-')sgn = -1;
        x = c - '0';while(isdigit(c = nc()))x = x * 10 + c - '0';x *= sgn;
    }
}

using namespace FastRead;
using namespace std;

const ll N = 3e5 + 10;
const ll M = 1e9 + 7;
const ld PI = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int a , b;

int gcd(int a , int b)
{
    if(!b) return a;
    return gcd(b , a % b);
}

signed main()
{
	#ifndef ONLINE_JUDGE
		FastIO , FILES;
	#endif


    int q; cin>>q;
    while(q--)
    {
        cin >> a >> b;
        cout << gcd(a , b) << '\n';
    }

    return 0;
}
