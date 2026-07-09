#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int INF=1e9+7;
const ll INFF=1e18+7;
#define nl '\n'
void __print(int x) { cout << x; }
void __print(long x) { cout << x; }
void __print(long long x) { cout << x; }
void __print(unsigned x) { cout << x; }
void __print(unsigned long x) { cout << x; }
void __print(unsigned long long x) { cout << x; }
void __print(float x) { cout << x; }
void __print(double x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << '\'' << x << '\''; }
void __print(const char* x) { cout << '\"' << x << '\"'; }
void __print(const string& x) { cout << '\"' << x << '\"'; }
void __print(bool x) { cout << (x ? "true" : "false"); }
template<typename T, typename V>
void __print(const pair<T, V>& x) { cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}'; }
template<typename T>
void __print(const T& x) { int f = 0; cout << '{'; for (auto& i : x) cout << (f++ ? "," : ""), __print(i); cout << "}"; }
void _print() { cout << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) { __print(t); if (sizeof...(v)) cout << ", "; _print(v...); }
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n), b(m), ans;
    for(int& i:a) cin>>i;
    for(int& i:b) cin>>i;
    vector<vector<int>> dp(n,vector<int>(m));
    for(int i=0; i<n; i++) dp[0][i]=(a[i]==b[0]);
    for(int i=0; i<m; i++) dp[i][0]=(b[i]==a[0]);
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(b[i]==a[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    for(int i=m-1; i>0;){
        for(int j=n-1; j>0;){
            if(b[i]==a[j]){
                ans.emplace_back(a[j]);
                i--,j--;
            }
            else if(dp[i][j-1]>=dp[i-1][j]) j--;
            else i--;
        }
    }
    cout<<dp[m-1][n-1]<<nl;
    for(int i=ans.size()-1; i>=0; i--) cout<<ans[i]<<" "; 
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);


    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    // int t;
    // cin >> t;
    for(int tt=1; tt<=t; tt++){
        // cout<<"#Case "<<t<<nl;
        solve();
    }
    return 0;
}