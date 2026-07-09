#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int NMAX=(1<<10)+1;
int a[NMAX],b[NMAX],dp[NMAX][NMAX],n,m,sol[NMAX];
inline void D(int i,int j)
{
    if(i==0 || j==0)
        return ;
    if(a[i]==b[j])
    {
        D(i-1,j-1);
        fout<<a[i]<<" ";
    }
    else if(dp[i-1][j]<dp[i][j-1])
        D(i,j-1);
    else D(i-1,j);
}
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
    D(n,m);
    fin.close();
    fout.close();
    return 0;
}
