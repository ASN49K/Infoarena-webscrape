#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int nmax=1030;
const int mmax=1030;

int n,m,ind,a[nmax],b[mmax],ab[nmax],dp[nmax][mmax];

int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int j=1;j<=m;j++)
        fin>>b[j];

    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--)
            if(a[i]==b[j])
                dp[i][j]=max(dp[i+1][j],dp[i][j+1])+1;
            else
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);

    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            fout<<dp[i][j]<<" ";
        fout<<"\n";
    }*/

    fout<<dp[1][1]<<"\n";

    int i=n,j=m;
    while(i>=1 && j>=1)
    {
        if(a[i]==b[j])
        {
            ab[++ind]=a[i];
            i--;
            j--;
        }
        else if(dp[i-1][j]<dp[i][j-1])
            j--;
        else
            i--;
    }

    for(int k=ind;k>=1;k--)
        fout<<ab[k]<<" ";
    return 0;
}
