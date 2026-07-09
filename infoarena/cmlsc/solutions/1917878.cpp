#include <bits/stdc++.h>
#define Nmax 1030
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,dp[Nmax][Nmax],a[Nmax],b[Nmax];
void Citire()
{
    int i;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    fin.close();
}
inline void Reconst(int x,int y)
{
    if(x==0||y==0) return;
    if(a[x]==b[y])
    {
        Reconst(x-1,y-1);
        fout<<a[x]<<" ";
    }
    else
    {
        if(dp[x][y-1]>dp[x-1][y]) Reconst(x,y-1);
        else Reconst(x-1,y);
    }
}
void Rezolvare()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    fout<<dp[n][m]<<"\n";
    Reconst(n,m);
    fout.close();
}
int main()
{
    Citire();
    Rezolvare();
    return 0;
}
