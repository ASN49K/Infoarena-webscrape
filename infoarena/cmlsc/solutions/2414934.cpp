#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,a[1025],b[1025],dp[1025][1025],c[1025],k;

int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
         fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(a[i]==b[j])
            dp[i][j]=1+dp[i-1][j-1];
        else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    while(n>=1 and m>=1)
    {
        if(a[n]==b[m])
        {
            c[++k]=a[n];
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
