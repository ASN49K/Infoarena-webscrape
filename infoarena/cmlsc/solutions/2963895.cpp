#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[2005],b[2005];
int dp[1050][1050];
int sol[1050];
int n,m,p;

int main()
{
    int i,j;
    fin >> n >>m;
    for(i=1;i<=n;i++) fin >> a[i];
    for(i=1;i<=m;i++) fin >> b[i];
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i]==b[j]) dp[i][j] = dp[i-1][j-1] +1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    fout << dp[n][m] <<"\n";
    i=n;j=m;
    while(i>=1 && j>=1){
        if(a[i]==b[j]){
            sol[++p]=a[i];
            i--;j--;
        }
        if(dp[i-1][j]<dp[i][j-1]){
            j--;
        }
        else{
            i--;
        }
    }
    for(i=p;i>=1;i--) fout << sol[i]<< " ";
    fin.close();
    fout.close();
    return 0;
}
