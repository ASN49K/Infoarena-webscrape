#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define pi pair<ll, ll>
#define sz(x) (int)((x).size())
#define all(a) (a).begin(), (a).end()

/* int f[maxn],nf[maxn],inv[maxn];
const int M=998244353;
void init(){
    inv[1]=1; for (int i=2;i<maxn;i++) inv[i]=M-1ll*(M/i)*inv[M%i]%M;
    f[0]=nf[0]=1; for (int i=1;i<maxn;i++) f[i]=1ll*f[i-1]*i%M,nf[i]=1ll*nf[i-1]*inv[i]%M;
}
int C(int x,int y){return 1ll*f[x]*nf[y]%M*nf[x-y]%M;}*/
const ll mod = 1e9+7;
ll n, k, m, mi, ma;

ll gcd(ll x, ll y){
	if(x == 0) return y;
	return gcd(y%x, x);
}

void solve(){
	
	ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");
	
	
	cin >> n;
	for(int i = 0; i<n; i++){
		ll u, v;
		cin >> u >> v;
		cout << gcd(u, v) << "\n";
	}
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t=1;
	//cin >> t;
	while(t--) solve();
	
	return 0;
}

