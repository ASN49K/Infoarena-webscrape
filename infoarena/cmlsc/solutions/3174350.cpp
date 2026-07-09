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
    for(int i=0;i<n;i++)
    {
        dp[i][0]=0;
    }
    for(int j=0;j<m;j++)
    {
        dp[0][j]=0;
    }
}

void afisare()
{
    int ct=0;
    fout<<dp[n][m]<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(dp[i][j]!=ct)
            {
                fout<<b[j]<<" ";
                ct++;
            }
        }
    }
}

int main()
{
    citire();
    initializare();
    parcurgere();
    afisare();
    return 0;
}
