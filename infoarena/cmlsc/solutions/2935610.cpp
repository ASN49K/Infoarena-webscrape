#include <iostream>
#include <fstream>
using namespace std;


ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");


int n,m,i,j;
int a[1030],b[1030];
int dp[1030][1030];
int sol[1030];


void read()
{
    fin>>n>>m;
    for(i=1; i<=n; i++)
    {
        fin>>a[i];
    }
    for(i=1; i<=m; i++)
    {
        fin>>b[i];
    }
}


void solve()
{
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int k=dp[n][m];
    fout<<k<<"\n";
    for(i=n,j=m; i;)
    {
        if(a[i]==b[j])
        {
            sol[k--] = a[i];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]) i--;
        else j--;
    }
    for(int i=1; i<=dp[n][m]; i++)
    {
        fout<<sol[i]<<" ";
    }
}


int main()
{
    read();
    solve();
    return 0;
}
