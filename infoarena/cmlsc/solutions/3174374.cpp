#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,a[1025],b[1025],dp[1025][1025];

void parcurgere()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
}

void citire()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fin>>a[i];
    }
    for(int j=1;j<=m;j++)
    {
        fin>>b[j];
    }
}

void initializare()
{
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(int j=0;j<=m;j++)
    {
        dp[0][j]=0;
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
    initializare();
    parcurgere();
    fout<<dp[n][m]<<endl;
    elem(n,m);
    return 0;
}
