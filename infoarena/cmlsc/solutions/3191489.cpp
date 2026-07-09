#include <fstream>
#include <iostream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m, dp[1124][1124], v[1124], a[1124],b[1124];
int main()
{
    fin>>n>>m;

    for(int i=1;i<=n;++i)
        fin>>a[i];
    for(int i=1;i<=m;++i)
        fin>>b[i];

    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i]==b[j])
                dp[i][j]=max(dp[i][j-1]+1, dp[i-1][j]);
            else
                dp[i][j]=max(dp[i][j-1], dp[i-1][j]);

    fout<<dp[n][m]<<'\n';

    int i=n,j=m, x=0;

    while(dp[i][j]!=0)
    {
        v[x++]=a[i];
        --i;
        --j;

        while(dp[i][j]!=0 && dp[i][j]==dp[i][j-1])
            --j;
        while(dp[i][j]!=0 && dp[i][j]==dp[i-1][j])
            --i;

    }


    for(int i=dp[n][m]-1;i>=0;--i)
        fout<<v[i]<<" ";

    return 0;
}
