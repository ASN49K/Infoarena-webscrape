#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    int n,m;
    fin>>n>>m;
    int a[n+1],b[m+1];
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    for(int i = 1; i <= m; i++)
        fin >> b[i];
    int dp[n+1][m+1];
    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i <= m ; i++){
        dp[0][i] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = (a[i] == b[j]) + max(dp[i][j-1], dp[i-1][j]);

        }
    }
    fout << dp[n][m];
    return 0;
}
