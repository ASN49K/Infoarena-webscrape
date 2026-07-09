#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmslc.in");
ofstream fout("cmslc.out");
const int N=1025;
int n,m,a[N],b[N],dp[N][N],sol[N*N];
void Citire()
{
    int i;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
}
void Rezolvare()
{
    int i,j;
    for(i=1;i<=n;i++)
         for(j=1;j<=m;j++)
            if(a[i]==b[j])
          dp[i][j]=dp[i-1][j-1]+1;
    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    fout<<dp[n][m]<<"\n";
    i=n;
    j=m;
    int nsol=0;
    while(i>=1 && j>=1)
    {
        if(a[i]==b[j])
        {
            sol[++nsol]=a[i];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
             i--;
        else j--;
    }
    for(i=nsol;i>=1;i--)
        fout<<sol[i]<<" ";
    fout<<"\n";
}
int main()
{
    Citire();
    Rezolvare();
    fin.close();
    fout.close();
    return 0;
}
