#include <bits/stdc++.h>
#define nmax 1030
#define infinit 100000000
using namespace std;
ifstream fin("cmslc.in");
ofstream fout("cmslc.out");
int a[nmax],b[nmax],dp[nmax][nmax],n,m,sol[nmax];
void Citire()
{
    int i;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
}
void DP()
{
    int i,j,maxim=-infinit,nsol=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
          if(a[i]==b[j])
           dp[i][j]=dp[i-1][j-1]+1;
    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
        maxim=max(maxim,dp[i][j]);
    fout<<maxim<<"\n";
    i=n;
    j=m;
    while(i>0 and j>0)
    {
          if(a[i]==b[j])
        {
            sol[++nsol]=a[i];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    for(i=nsol;i>=1;i--)
        fout<<sol[i]<<" ";
}
int main()
{
    Citire();
    DP();
    fin.close();
    fout.close();
    return 0;
}
