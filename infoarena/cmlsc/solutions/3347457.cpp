#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025],b[1025],dp[1025][1025],sol[1025];

int main()
{
    int n,m;
    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>a[i];
    for(int i=1; i<=m; i++)
        fin>>b[i];

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    int lg=dp[n][m];
    int i=n,j=m,p=lg;

    while(i>0 && j>0)
    {
        if(a[i]==b[j])
        {
            sol[p]=a[i];
            p--;
            i--;
            j--;
        }
        else if(dp[i-1][j]>=dp[i][j-1])
            i--;
        else
            j--;
    }

    fout<<lg<<"\n";
    for(int i=1; i<=lg; i++)
        fout<<sol[i]<<" ";

    return 0;
}
