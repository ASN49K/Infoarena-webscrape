#include <bits/stdc++.h>
#define fri(a, b) for (int i = (a); i < (b); ++i)
#define frj(a, b) for(int j = a; j < b; j++)
#define frk(a, b) for(int k = a; k < b; k++)
#define frm(a, b, i) for(int i = b; i >= a; i--)
#define ll long long
#define all(x) x.begin(), x.end()
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
#define sz size()
#define rall(x) x.rbegin(), x.rend()
#define ct(x) cout << x
#define cts(x) cout << x << ' '
#define ctn(x) cout << x << '\n'
using namespace std;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using ml = map<ll, ll>;
template <typename T>void read(T n, vector<T> &a){fri(0, n){cin >> a[i];}}
template<typename T> void print(T n, vector<T> &a){fri(0, n){cts(a[i]);}}
 
const int mx = 1000001;

string __fname = "cmlsc"; ifstream in (__fname + ".in"); ofstream out (__fname + ".out"); 
#define cin in 
#define cout out
int n, m;
int a[1025];
int b[1025];
int dp[1026][1026];

void solve(){
    cin >> n >> m;
    fri(0, n){
        cin >> a[i];
        dp[i][0] = 0;
    }
    dp[n][0];
    fri(0, m){
        cin >> b[i];
        dp[0][i] = 0;
    }
    dp[0][m] = 0;
    fri(1, n + 1){
        frj(1, m + 1){
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    ctn(dp[n][m]);
    vi ans;
    int i = n;
    int j = m;
    while(i != 0  && j != 0){
        if(dp[i][j] != dp[i - 1][j] && dp[i][j] != dp[i][j - 1]){
            i--;
            j--;
            ans.pb(a[i]);
        }
        if(dp[i][j] == dp[i][j - 1]){
            j--;
        }
        if(dp[i][j] == dp[i - 1][j]){
            i--;
        }
    }
    reverse(all(ans));
    fri(0, ans.sz){
        cts(ans[i]);
    }
    ct('\n');
}
 

int main()
{   
    ios_base::sync_with_stdio(0); cin.tie(0);
    // int t;
    // cin >> t;
    // while(t--)
        solve();
}