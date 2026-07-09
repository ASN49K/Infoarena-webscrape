#include <bits/stdc++.h>
//Soltan Cristian
#define fri(a, b) for (int i = (a); i < (b); ++i)
#define frj(a, b) for(int j = a; j < b; j++)
#define frk(a, b) for(int k = a; k < b; k++)
#define frm(a, b, i) for(int i = b; i >= a; i--)
#define ll long long
#define all(x) x.begin(), x.end()
#define mod 1000000007
#define pb push_back
#define st first
#define nd second
#define sz size()
#define rall(x) x.rbegin(), x.rend()
#define ct(x) cout << x
#define cts(x) cout << x << ' '
#define ctn(x) cout << x << '\n'
#define Y cout << "YES" << '\n'
#define N cout << "NO" << '\n'
using namespace std;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vb = vector<bool>;
using ml = map<ll, ll>;
using vii = vector<vector<int>>;
using vll = vector<vector<ll>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template <typename T>void read(T n, vector<T> &a){fri(0, n){cin >> a[i];}}
template<typename T>void print(T n, T m, vector<vector<T>> &dp){fri(0, n){ct('\n');frj(0, m){ct(setw(5));cts(dp[i][j]);}}}


const int mx = 1000001;
string __fname = "euclid2"; ifstream in(__fname + ".in"); ofstream out(__fname + ".out");
#define cin in 
#define cout out



void solve(){
    int a, b;
    cin >> a >> b;
    ctn(__gcd(a, b));


}
 
  
int main()
{   
    ios_base::sync_with_stdio(0); cin.tie(0); ct(fixed); ct(setprecision(12)); 
    int t;
    cin >> t;
    while(t--)
        solve();
}