#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1025],b[1025],dp[1025][1025],i,j,k,subsir[1025],maxi;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(j=1;j<=m;j++)
        f>>b[j];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                if(dp[i][j]>=maxi)
                {
                    maxi=dp[i][j];
                    subsir[k++]=a[i];
                }
            }
            else
                dp[i][j]==max(dp[i-1][j],dp[i][j-1]);

        }
    g<<maxi+1<<endl;
    for(i=0;i<k;i++)
        g<<subsir[i]<<" ";
    return 0;
}