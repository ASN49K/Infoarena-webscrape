#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define ll long long
#define pi pair<int,int>
#define pl pair<ll,ll>
#define lg length()
#define sz size()
#define pb push_back
#define MAXN 200005
#define int long long

int n,m;
int a[1030],b[1030];
int d[1030][1030];
vector <int> sol;
signed main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++){
        if (a[i] == b[j]) d[i][j] = d[i-1][j-1] + 1;
        else d[i][j] = max(d[i-1][j], d[i][j-1]);
    }
    while (n && m){
        if (a[n] == b[m]) sol.pb(a[n]), n--, m--;
        else if (d[n][m-1] < d[n-1][m]) n--;
        else m--;
    }
    for (int i = sol.sz - 1; i >= 0; i--)
        cout << sol[i] << ' ';
}
