#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[2005],b[2005];
int dp[1050][1050];
int n,m;

int main()
{
    int i,j;
    fin >> n >>m;
    for(i=1;i<=n;i++) fin >> a[i];
    for(i=1;i<=m;i++) fin >> b[i];
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+(a[i]==b[j]);
        }
    }
    fout << dp[n][m] <<"\n";
    i=1;j=1;
    while(i<=n && j<=m){
        if(a[i]==b[j]) fout << a[i] << " ";
        if(dp[i+1][j]<dp[i][j+1] && j<m) j++;
        else i++;
    }
    return 0;
}
