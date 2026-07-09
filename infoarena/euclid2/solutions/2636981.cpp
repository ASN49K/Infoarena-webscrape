#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

typedef long long ll;

const ll mod=1e9+7;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define rc(x)  return cout<<x<<"\n",0
#define sz(s)  (int) s.size()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;

ll t;
int euclid(int a, int b) {
	if (!b)return a;
	return euclid(b,a%b);
}
int main() {
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	ifstream cin("euclid.in");
//	ofstream cout("euclid.out");
	cin >> t;
	while (t--) {
		ll a,b; 
		cin >> a >> b;
		cout << euclid(a,b) << '\n';
	}
}

