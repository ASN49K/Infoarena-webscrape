#include <bits/stdc++.h>
using namespace std;
const int NMAX = (1<<10)+2;
int n,m,a[NMAX],b[NMAX],dp[NMAX][NMAX],maxi;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        fin >> b[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i] == b[j]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            maxi = max(maxi, dp[i][j]);
        }
    }
    fout << dp[n][m] << "\n";
    vector<int> sol;
    int i = n, j = m;
    while(i && j){
        if(a[i] == b[j]){
            sol.push_back(a[i]);
            i--; j--;
        }else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    reverse(sol.begin(), sol.end());
    for(int it: sol){
        fout << it << " ";
    }
    return 0;
}
