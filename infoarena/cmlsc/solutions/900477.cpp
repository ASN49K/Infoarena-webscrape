#include <iostream>
#include <fstream>
#define DN 1030
#define mp make_pair
using namespace std;

int a[DN],b[DN],dp[DN][DN],rez[DN];

int main()
{
    int n,m;
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n>>m;

    for(int i=1;i<=n;++i)
        f>>a[i];
    for(int i=1;i<=m;++i)
        f>>b[i];

    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
         {
               if(a[i]==b[j])
                    dp[i][j]=1+dp[i-1][j-1];
                dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
         }
    for(int i=n,j=m;i;)
        if(a[i]==b[j])
            rez[++rez[0]]=a[i],--i,--j;
        else
            if(dp[i-1][j]>dp[i][j-1])
                --i;
                else
                    --j;

    g<<dp[n][m]<<"\n";
    for(int i=rez[0];i>=1;--i)
        g<<rez[i]<<" ";
    return 0;
}

