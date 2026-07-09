#include <bits/stdc++.h>
#define Nmax 1030

using namespace std;
int dp[Nmax][Nmax],n,m,i,j,a[Nmax],b[Nmax],c[Nmax],t;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i] ;
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }

    }
    i=n;
    j=m;
    while(i>0 and j>0)
    {
        if(a[i]==b[j])
        {
            c[++t]=a[i];
            i--;
            j--;
        }
        else if( dp[ i ][ j - 1 ] > dp[ i - 1 ][ j ])
                    j--;
            else
                    i--;
    }
    fout<<t<<"\n";
        for(i=t;i>0;i--)
            fout<<c[i]<<" ";
    return 0;
}
