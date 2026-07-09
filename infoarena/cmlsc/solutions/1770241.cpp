#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

#define lim 1024
int dp[lim][lim],a[lim],b[lim],rez[lim];
int n,m,best;

int main()
{
    int i,j;

    fin>>n>>m;
    for(i=1; i<=n; i++)
        fin>>a[i];
    for(i=1; i<=m; i++)
        fin>>b[i];

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);


    best=0;
    for(i=n, j=m; i; )
    {
        if(a[i]==b[j])
            rez[++best]=a[i], i--, j--;
        else
            if(dp[i-1][j]<dp[i][j-1])
                j--;
            else
                i--;
    }


    fout<<best<<'\n';
    for(i=best; i; i--)
        fout<<rez[i]<<' ';

    return 0;
}
