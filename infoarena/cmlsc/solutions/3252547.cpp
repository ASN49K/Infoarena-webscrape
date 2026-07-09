#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025],b[1025],n,m,i,j,maxim,x,y,dp[1025][1025];
vector<int> sir;
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            dp[i][j] = max(dp[i-1][j-1]+(a[i]==b[j]),max(dp[i-1][j],dp[i][j-1]));
            maxim = max(maxim, dp[i][j]);
        }
    }
    fout<<maxim<<'\n';
    i=n; j=m;
    while(i && j){
        if(a[i] == b[j]){
            sir.push_back(a[i]);
            i--; j--;
        }else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    for(i=sir.size()-1;i>=0;i--)
        fout<<sir[i]<<' ';
    return 0;
}
