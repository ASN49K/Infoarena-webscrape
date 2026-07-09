#include <iostream>
#include <fstream>
#define NMAX 1110
using namespace std;
ifstream fin("cmlsc.in");
ofstream gout("cmlsc.out");
int a[NMAX], b[NMAX], dp[NMAX][NMAX],n,m,v[NMAX],k,maxi;

void citire()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
}

void matrice()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(a[i]==b[j])
            dp[i][j]=1+dp[i-1][j-1];
        else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
}

int main()
{
    citire();
    matrice();
    gout<<dp[n][m]<<'\n';
    maxi=dp[n][m];
    while(maxi>0)
    {
        if(a[n]==b[m])
        {
            v[k]=a[n];
            k++;
            n--;
            m--;
            maxi--;
        }
        else
        {
            if(dp[n][m-1]>dp[n-1][m])
                n--;
            else m--;
        }
    }
    for(int i=k-1;i>=0;i--)
        gout<<v[i]<<" ";
    return 0;
}
