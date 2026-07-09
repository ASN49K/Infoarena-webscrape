#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
int a[1100],b[1100],dp[1100][1100],v[1100];

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int m,n;
    f >> m >> n;
    for(int i=1;i<=m;++i)
    {
        f >> a[i];
    }
    for(int i=1;i<=n;++i)
    {
        f >> b[i];
    }
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    g << dp[m][n] << "\n";
    int k=1;
    while(m&&n)
    {
        if(a[m]==b[n])
        {
            v[k]=a[m];
            ++k;
            m--;
            n--;
        }
        else
        {
            if(dp[m-1][n]>dp[m][n-1])
            {
                m--;
            }
            else
            {
                n--;
            }
        }
    }
    for(int i=k-1;i>=1;--i)
    {
        g << v[i] << " ";
    }
    return 0;
}
