#include<bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in"); ofstream g("cmlsc.out");
const int N=1030;
int n,m,a[N],b[N],t[N],dp[N][N];
int main()
{   f>>n>>m;
    for(int i=1;i<=n;i++)f>>a[i];
    for(int i=1;i<=m;i++)f>>b[i];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(a[j]==b[i]) dp[i][j]=dp[i-1][j-1]+1; else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
    int l=0;
    for(int i=n,j=m;i;)
        if(a[i]==b[j]) {t[++l]=a[i]; i--; j--;}
            else {if(dp[j-1][i]<dp[j][i-1]) i--; else j--;}
    g<<dp[m][n]<<'\n';
    for(int i=l;i>=1;i--) g<<t[i]<<' ';
    g.close(); return 0;
}
