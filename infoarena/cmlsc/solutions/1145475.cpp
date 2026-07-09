#include <fstream>
#include<algorithm>
using namespace std;
ifstream f("cmlsc.in"); ofstream g("cmlsc.out");
int m,n,vmax,a[1045],b[1045],dp[1045][1045],sir[1045];
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++) f>>a[i];
    for(int i=1;i<=m;i++) f>>b[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    g<<dp[n][m]<<'\n';
    int i=n,j=m;
    while(i&&j)
    {
        if(a[i]==b[j]) sir[++vmax]=a[i],--i,--j;
        else if(dp[i-1][j]==dp[i][j]) i--;
        else j--;
    }
    for(i=vmax;i;i--) g<<sir[i]<<' ';
    g.close();
    return 0;
}
