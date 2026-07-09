#include <bits/stdc++.h>
using namespace std;
const int NMAX = (1<<10)+5;
int n,m,a[NMAX],b[NMAX],dp[NMAX][NMAX];

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
    }
    for(int j = 1; j <= m; j++){
        fin >> b[j];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(a[i] == b[j]){
                dp[i][j] = max(dp[i][j], 1+dp[i-1][j-1]);
            }
        }
    }
    fout << dp[n][m] << "\n";
    vector<int> ans;
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(a[i] == b[j]){
            ans.push_back(a[i]);
            i--; j--;
        }else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for(int it: ans){
        fout << it << " ";
    }
    return 0;
}
