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

void solve(){
	
	ifstream cin("cmlsc.in");
	ofstream cout("cmlsc.out");
	
	cin >> n >> m;
	vector<ll> a(n), b(m);
	ll dp[n + 5][m + 5], u[n + 5][m + 5];
	for(int i = 0; i<n; i++){
		cin >> a[i];
		dp[i + 1][0] = 0;
	}
	dp[0][0] = 0;
	for(int i = 0; i<m; i++){
		cin >> b[i];
		dp[0][i + 1] = 0;
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(dp[i + 1][j] > dp[i][j + 1]) u[i + 1][j + 1] = 1; else u[i + 1][j + 1] = 2;
			dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			if(a[i] == b[j] && dp[i][j] + 1 >= dp[i + 1][j + 1]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
				u[i + 1][j + 1] = 3;
			}
		}
	}
	ll x = n, y = m;
	vector<ll> ans;
	cout << dp[n][m] << "\n";
	while(x*y){
		if(u[x][y] == 3){
			ans.pb(a[x - 1]);
			x--; y--;
			continue;
		}
		if(u[x][y] == 1) y--; else x--;
	}
	reverse(all(ans));
	for(int i = 0; i<ans.size(); i++) cout << ans[i] << " ";
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t=1;
	//cin >> t;
	while(t--) solve();
	
	return 0;
}

