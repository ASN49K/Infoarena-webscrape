#include <bits/stdc++.h>
#define nmax 1024
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n,m,a[nmax],b[nmax],dp[nmax][nmax];
vector <int> sol;
void read(){
    in >> n >> m;
    for(int i=1; i<=n; i++) in >> a[i];
    for(int i=1; i<=m; i++) in >> b[i];
}
void solve(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            if(a[i]==b[j]){
                dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
            }
        }
    }
}
void afis(){
    out << dp[n][m] << '\n';
    for(int i=n, j=m; i!=0 && j!=0;){
        if(a[i]==b[j]){
            sol.push_back(a[i]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
    }
    for(int i=sol.size()-1; i>=0; i--){
        out << sol[i] << ' ';
    }
}
int main(){
    read();
    solve();
    afis();
}
