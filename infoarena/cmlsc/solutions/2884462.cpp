#include <bits/stdc++.h>
#define ll long long
using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

const int N_MAX = 1500;

int n , m;
int a[N_MAX] , b[N_MAX] , dp[N_MAX][N_MAX];
vector<int>ans;


void solve(){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (a[i] == b[j]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
            }
        }
    }
    int l = n , c = m;
    while (l && c){
        if (a[l] == b[c]){
            ans.push_back(a[l]);
            l -= 1;
            c -= 1;
        }
        else{
            if (dp[l][c] == dp[l - 1][c]){
                l -= 1;
            }
            else{
                c -= 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    fin >> n >> m;
    for (int i=1; i<=n; i++){
        fin >> a[i];
    }
    for (int i=1; i<=m; i++){
        fin >> b[i];
    }

    solve();

    reverse(ans.begin() , ans.end());
    fout << ans.size() << '\n';
    for (auto i : ans){
        fout << i << " ";
    }
}
