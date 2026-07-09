#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,a[1030],b[1030],dp[1025][1025];
void citire()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
}
void solutie()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    fout<<dp[n][m]<<"\n";
    int i=n,j=m;
    int sol[1030],nr=0;
    while(i>=1 && j>=1)
    {
        if(a[i]==b[j])
        {
            sol[++nr]=a[i];
            i--;
            j--;
        }
        else if(dp[i][j-1]>dp[i-1][j])
            j--;
        else i--;
    }
    for(int i=nr;i>=1;i--)
        fout<<sol[i]<<" ";
}
int main()
{
    citire();
    solutie();
    return 0;
}
