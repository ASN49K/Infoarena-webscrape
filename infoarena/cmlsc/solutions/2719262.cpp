#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1030],b[1030],n,m,dp[1030][1030],c[1030],k;
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
            dp[i][j]=dp[i-1][j-1]+1;
        else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    int i=n;
    int j=m;
    while(i>=1&&j>=1)
    {
        if(a[i]==b[j])
            {
                c[++k]=a[i];
                i--;
                j--;
            }
         else
            if(dp[i-1][j]>dp[i][j-1])
              i--;
              else
                j--;
    }
    fout<<k<<"\n";
    for(int i=k;i>=1;i--)
        fout<<c[i]<<" ";
    return 0;
}
