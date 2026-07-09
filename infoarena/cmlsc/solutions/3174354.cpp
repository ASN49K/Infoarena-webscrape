#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m;
int a[2025];
int b[2025];
int dp[2025][2025];
void citire()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int j=1;j<=m;j++)
        fin>>b[j];
}
void genmat()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
}
void afisare()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            fout<<dp[i][j]<<" ";
        fout<<'\n';
    }
}
void elem(int i,int j)
{
    if(dp[i][j]==0)
    {
        return;
    }
    if(a[i]==b[j])
    {
        elem(i-1,j-1);
        fout<<a[i]<<" ";
    }
    else
    {
         if(dp[i-1][j]>dp[i][j-1])
             elem(i-1,j);
         else
            elem(i,j-1);
    }
}
int main()
{
    citire();
    genmat();
    afisare();
    fout<<dp[n][m]<<'\n';
    elem(n,m);
    return 0;
}
