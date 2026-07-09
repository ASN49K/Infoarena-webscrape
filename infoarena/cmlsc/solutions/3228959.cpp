#include <bits/stdc++.h>
#include <cstring>
#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[1025], b[1025], dp[1025][1025], ans[2000], rasp;
int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        fin>>a[i];
    }
    for(int i=1; i<=m; i++)
    {
        fin>>b[i];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else {
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int i=n, j=m;
    while(i>0&&j>0)
    {
        if(a[i]==b[j])
        {
            ans[++rasp]=a[i];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]) i--;
        else j--;
    }
    fout<<rasp<<'\n';
    for(int k=rasp; k>=1; k--)
    {
        fout<<ans[k]<<' ';
    }
    return 0;
}

