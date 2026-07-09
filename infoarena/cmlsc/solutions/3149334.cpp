#include <bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,a[1001],b[1001],dp[1005][1005],sc[2001],k;
//complexitate O(n*m)
int main()
{
    f>>n>>m;
    for(i=1;i<=n;++i) f>>a[i];
    for(i=1;i<=m;++i) f>>b[i];
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j] , dp[i][j-1]);
    }
    g<<dp[n][m]<<'\n';
    i=n; j=m;
    while(i>=1 && j>=1){
        if(a[i]==b[j]){ ++k; sc[k]=a[i]; --i; --j;}
        else{
            if(dp[i-1][j]>dp[i][j-1]) --i;
            else --j;
        }
    }
    for(i=k;i>=1;--i) g<<sc[i]<<' ';
    return 0;
}
/**
4 6
6 1 3 9
1 3 6 2 9 8

8 5
2 1 5 3 4 5 2 7
1 5 5 7 4

8 5
2 1 5 3 4 5 2 7
1 5 7 -5 4
*/
