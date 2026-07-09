#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int nmax=1025;
int n,m,dp[nmax][nmax],a[nmax],b[nmax],sol[nmax*nmax],pas;
///dp[i][j]-lungimea maxima a unui subsir comun aflat in subsecventa [1..i]
///respectiv [1..j]
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    fout<<dp[n][m]<<"\n";
    ///reconstruiesc solutia
    int i=n,j=m;
    while(i>=1 && j>=1)
    {
        if(a[i]==b[j])
        {
            ++pas;
            sol[pas]=a[i];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    for(int i=pas;i>=1;i--)
        fout<<sol[i]<<" ";
    fin.close();
    fout.close();
    return 0;
}
