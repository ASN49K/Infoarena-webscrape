#include<fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[1050],b[1050],dp[1026][1026],v[1050];
int main()
{
    int m,n,i,j,x;
    in>>m>>n;
    for(i=1;i<=m;i++)
        in>>a[i];
    for(i=1;i<=n;i++)
        in>>b[i];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=1+dp[i-1][j-1];

            }
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    x=dp[m][n];
    i=m;j=n;
    while(x!=0)
    {
        if(a[i]==b[j]&&dp[i][j]==x)
        {
            v[x]=a[i];
            x--;
        }
        if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    out<<dp[m][n]<<'\n';
    for(i=1;i<=dp[m][n];i++)
        out<<v[i]<<" ";
    return 0;
}
