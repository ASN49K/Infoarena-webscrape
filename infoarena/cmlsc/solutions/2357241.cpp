#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,a[1026],b[1026],dp[1026][1026];

int main()
{
    fin>>m>>n;
    for(int i=1;i<=m;i++)
        fin>>a[i];
    for(int j=1;j<=n;j++)
        fin>>b[j];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    fout<<dp[m][n]<<'\n';
   /* for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
            fout<<dp[i][j]<<" ";
        fout<<endl;
    } */
    int i=m;
    int j=n;
    int sol[1026];
    int x=0;
    while(dp[i][j])
    {
        while(dp[i][j]==dp[i-1][j])
            i--;
        while(dp[i][j]==dp[i][j-1])
            j--;
        x++;
        sol[x]=b[j];
        i--;

    }
    for(i=x;i>=1;i--)
        fout<<sol[i]<<" ";

}
