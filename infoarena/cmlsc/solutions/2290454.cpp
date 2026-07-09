#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <ctime>
#include <unordered_map>
#include <iomanip>
#include <complex>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define deb(a) cerr<< #a << "= " << (a)<<"\n";

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ld;
typedef complex<double> base;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<class T> ostream& operator<<(ostream& stream, const vector<T> v){ stream << "[ "; for (int i=0; i<(int)v.size(); i++) stream << v[i] << " "; stream << "]"; return stream; }
ll fpow(ll x, ll p, ll m){ll r=1; for (;p;p>>=1){ if (p&1) r=r*x%m; x=x*x%m; } return r;}
ll inv(ll a, ll b){ return a<2 ? a : ((a-inv(b%a,a))*b+1)/a%b; }
int gcd(int a, int b){ if (!b) return a; return gcd(b,a%b);}
ll gcd(ll a, ll b){ if (!b) return a; return gcd(b,a%b);}


int N,M,a[1030],b[1030],dp[1030][1030];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ifstream cin("cmlsc.in");
	ofstream cout("cmlsc.out");
	cin >> N >> M;
	
	int i,j;
	for (i=1; i<=N; i++)
		cin >> a[i];
	
	for (i=1; i<=M; i++)
		cin >> b[i];
		
	for (i=1; i<=N; i++)
		for (j=1; j<=M; j++){
			if (a[i]==b[j]) dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	
	cout << dp[N][M] << "\n";
	
	int x=N,y=M;
	vi ans;
	while (x && y){
		if (a[x]==b[y]){
			ans.pb(a[x]);
			x--,y--;
		}
		else if (dp[x][y]==dp[x-1][y]) x--;
		else y--;
	}
	
	reverse(all(ans));
	for (int x : ans)
		cout << x << " ";
}

