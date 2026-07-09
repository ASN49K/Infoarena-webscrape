#include<bits/stdc++.h>
#define NMAX 1025
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,a[NMAX],b[NMAX],dp[NMAX][NMAX],afis[NMAX],nr;

int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        f>>a[i];
    for(int j=1;j<=m;++j)
        f>>b[j];

    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j)
        {
            if(a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]+=max(dp[i][j-1],dp[i-1][j]);

        }
    }


    for(int i=n,j=m;i;)
    {
        if(a[i]==b[j])
            afis[++nr]=a[i],i--,j--;
        else
            if(dp[i-1][j]<dp[i][j-1])
            j--;
        else
            i--;
    }
    g<<nr<<'\n';
    for(int i=nr;i;--i)
        g<<afis[i]<<' ';
}
