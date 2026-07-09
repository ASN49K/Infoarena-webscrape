#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(a) (a).begin(), (a).end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rc(s) return cout<<s,0
#define pi pair <int, int>
#define sz(x) (int)((x).size())
#define int long long

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

const ll inf = 2e9;
const ll mod = 998244353;
const int N = 2000 + 11;
const int NMAX = 1e4 + 11;
const ll INF64 = 3e18 + 1;
const double eps = 1e-14;
const double PI = acos(-1);

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m, a[N], b[N], sir[N], dp[N][N];

void solve(){

    in >> n >> m;

    for(int i = 1, x; i <= n; i++){
        in >> a[i];
    }

    for(int i = 1, x; i <= m; i++){
        in >> b[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j])dp[i][j] = dp[i - 1][j - 1] + 1;else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

        }
    }

    int k = 0, i = n, j = m;
    while(i){
        if(a[i] == b[j]){
            sir[++k] = a[i];
            i--; j--;
        }else
        if(dp[i - 1][j] < dp[i][j - 1])j--;else i--;
    }

    reverse(sir + 1, sir + k + 1);

    out << k << '\n';
    for(int i = 1; i <= k; i++)out << sir[i] << ' ';

}

int32_t main(){
ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    //cout << setprecision(20) << fixed;

    int t = 1;
   // cin >> t;
    while(t--){
        solve();
    }
}
