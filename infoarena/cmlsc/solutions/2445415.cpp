#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,k,i,j,num=0;
int a[1024],b[1024];
int sols[1024];
int dp[1024][1024];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;i<=m;i++)
        f>>b[i];
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++){
        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        if(a[i] == b[j]){
            sols[num] = a[i];
            num++;
            dp[i][j]++;
        }
    }
    g<<dp[n][m]<<'\n';
    for(i=0;i<num;i++)
        g<<sols[i]<<' ';
}
