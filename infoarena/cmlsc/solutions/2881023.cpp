#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define dbg(x) cout << #x <<": " << x << "\n";
#define sz(x) ((int)x.size())

using ll = long long;

const string fn = "cmlsc";
ifstream fin(fn + ".in");
ofstream fout(fn + ".out");

int n, m;
int a[1025], b[1025];
int dp[1025][1025];
int main(){

    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
    for (int j = 1; j <= m; ++j)
        fin >> b[j];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (a[i] == b[j])});
    fout << dp[n][m] << "\n";
    vector<int> ans;
    int i = n, j = m;
    while(i && j){
        if(a[i] == b[j])
        ans.pb(a[i]);
        if(dp[i - 1][j] > dp[i][j - 1])
            --i;
        else
            --j;
    }
    reverse(ans.begin(), ans.end());
    for(auto i : ans)
        fout << i << " ";
    return 0;
}