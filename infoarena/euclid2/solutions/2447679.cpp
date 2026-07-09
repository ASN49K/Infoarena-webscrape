# pragma GCC optimize("Ofast")
# pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f(i,a,b) for (int i = a; i <= b; i++)
#define fi(i,a,b) for (int i = a; i < b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rc(s) return cout<<s,0
#define er erase
#define in insert
#define pi pair <int, int>
#define pii pair <pi, pi>
# define sz(x) (int)((x).size())

ll t,a,b;

int32_t main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");
	for(cin>>t;t--;)cin>>a>>b,cout<<__gcd(a,b)<<'\n';
return 0;
}

