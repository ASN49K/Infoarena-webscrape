#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,top;
int st[1029], a[1029], b[1029], dp[1029][1029];

int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>a[i];
    for(int i=1; i<=m; i++)
        fin>>b[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    fout<<dp[n][m]<<"\n";
    int i=n, j=m;
    while(i&&j)
    {
        if(a[i]==b[j])
            st[++top]=a[i],i--,j--;
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else j--;
    }
    for(i=top;i>=1;i--)
        fout<<st[i]<<" ";
    return 0;
}
