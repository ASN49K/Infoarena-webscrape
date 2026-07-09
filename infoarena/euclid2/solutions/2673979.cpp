
#include <bits/stdc++.h>
using namespace std;

ifstream in ("euclid2.in");
ofstream out ("euclid2.out");

#define              ll              long long

#define       forn(i,n)              for(int i=0;i<n;i++)
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()

#define            pb                push_back
#define          sz(a)               (int)a.size()
#define         fastio               ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define cin in
#define cout out

ll pw(ll a,ll b,ll m){a%=m;ll r=1;while(b>0){if(b&1)r=(r*a)%m;a=(a*a)%m;b/=2;}return r;}
ll gcd(ll a, ll b) {if(!b)return a;return gcd(b,a % b);}
ll lcm(ll a,ll b){return(a*b)/gcd(a,b);}
ll fact(ll n, ll mod){ll ret=1;for(ll i=1;i<=n;i++)ret=(ret*i)%mod;return ret;}
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(ll i=5;i*i <= n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}

const int N = 5e5 + 10;
vector<int> adj[N];
int col[N];
void solve()
{
	int a,b;
	cin >> a >> b;
	cout << gcd(a,b) << "\n";
}

int32_t main()
{
	//fastio;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}