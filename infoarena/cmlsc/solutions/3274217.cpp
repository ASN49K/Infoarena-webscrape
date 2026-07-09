#include <bits/stdc++.h>
#define INF  0x3f3f3f3f
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,x[2001],y[2001],dp[2001][2001],sir[2001];

int main() {
    fin >> n >> m;
    for(int i=1; i<=n; ++i)
        fin>>x[i];
    for(int i=1; i<=m; ++i)
        fin>>y[i];
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            if(x[i]==y[j])
                dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

    fout<<dp[n][m]<<'\n';
    int i=n,j=m;
    int cnt=0;
    while(i>=1 && j>=1){
        if(x[i]==y[j]){
            sir[++cnt]=x[i];
            --i;
            --j;
        }
        else{
            if (dp[i - 1][j] < dp[i][j - 1]) {
                --j;
            } else {
                --i;
            }
        }
    }
    for(int i=cnt; i>=1; --i)
        fout<<sir[i]<<' ';
}
