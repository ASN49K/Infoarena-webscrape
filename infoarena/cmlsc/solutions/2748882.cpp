#include <bits/stdc++.h>
using namespace std;

int v[1026];
int a[1026];
int dp[1026][1026];
int sol[1026];

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int n, m;
    for(int i = 1; i <= n; i++)
        fin>>v[i];
    for(int j = 1; j <= m; j++)
        fin>>a[j];
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= m; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1] + (v[i]==a[j]));
        }
    }
   int k=dp[n][m];
    fout<<k<<'\n';

    int i=n,j=m;
    while(dp[i][j]!=0)
    {
        if(v[i]==a[j])
        {
            sol[dp[i][j]]=v[i];
            i--;j--;
        }
        else
            if(dp[i-1][j]>=d[i][j-1])
                i--;
            else
                j--;
    }
    for(int i=1;i<=k;i++)
        fout<<sol[i]<<' ';
    return 0;
}
