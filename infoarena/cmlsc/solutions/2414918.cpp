#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,a[1025],b[1025],dp[1025][1025],c[1025];

int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
         fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
    if(a[1]==b[1])
        dp[1][1]=1;
    else
        dp[1][1]=0;
    for(int i=2;i<=n;i++)
    {
        dp[i][1]=dp[i-1][1];
        if(a[i]==b[1])
            dp[i][1]=1;
    }
    for(int i=2;i<=m;i++)
    {
        dp[1][i]=dp[1][i-1];
        if(a[1]==b[i])
            dp[1][i]=1;
    }
    for(int i=2;i<=n;i++)
        for(int j=2;j<=m;j++)
    {
        dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        if(a[i]==b[j])
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
    }
    int k=0;
    while(n>=0 and m>=0)
    {
        if(a[n]==b[m])
        {
            k++;
            c[k]=a[n];
            n--;
            m--;
        }
        else
            if(dp[n-1][m]>dp[n][m-1])
            n--;
            else
            m--;
    }
    fout<<k<<"\n";
    for(int i=k;i>=1;i--)
        fout<<c[i]<<" ";
    return 0;
}
