#include <iostream>
#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,k,a[1026],b[1032],dp[1032][1032],sir[1025];
int main()
{
    f>>n>>m;
    for(int i=1; i<=n; i++)
    f>>a[i];
    for(int i=1; i<=m; i++)
    f>>b[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        if(a[i]==b[j])
            dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    for (int i = n, j = m; j;)
        if(a[i]==b[j])
            {
                sir[++k]=a[i];
                i--;
                j--;
            }else if(dp[i-1][j]>dp[i][j-1])i--;
                    else j--;
    g<<k<<"\n";
    for(int i=k; i>=1; i--)
        g<<sir[i]<<" ";

    return 0;

}

