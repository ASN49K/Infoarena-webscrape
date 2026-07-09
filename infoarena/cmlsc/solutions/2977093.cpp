#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1024],b[1024],dp[1024][1024],i,j,k,subsir[1024],maxi,ok;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(j=1;j<=m;j++)
        f>>b[j];
    for(i=1;i<=n;i++)
    {
        ok=1;
        for(j=1;j<=m;j++)
        {

            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                if(dp[i][j]>=maxi && ok==1)
                {
                    maxi=dp[i][j];
                    subsir[k++]=a[i];
                    ok=0;
                }
            }
            else
                dp[i][j]==max(dp[i-1][j],dp[i][j-1]);

        }
    }
    g<<maxi+1<<endl;
    g<<subsir[0];
    for(i=1;i<k;i++)
        g<<" "<<subsir[i];
    return 0;
}