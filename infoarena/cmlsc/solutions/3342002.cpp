#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,i,j,a[1030],b[1030],dp[1030][1030],v[1024],h;
int main()
{
    fin >> n >> m;
    for(i = 1; i<=n; i++)
    {
        fin >> a[i];
    }
    for(i = 1; i<=m; i++)
    {
        fin >> b[i];
    }
    for(i = 1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(a[i] != b[j])
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
            else
                dp[i][j] = dp[i-1][j-1]+1;
        }
    }
    i = n;
    j = m;
    fout << dp[i][j] << endl;;
    while(i!=0&&j!=0)
    {
        if(a[i] == b[j])
        {
            v[++h] = a[i];
            i = i-1;
            j = j-1;
        }
        else
        {
            if(dp[i-1][j]<dp[i][j-1])
            {
                j = j-1;
            }
            else
            {
                i = i-1;
            }
        }
    }
    sort(v+1,v+1+h);
    for(i = 1;i<=h;i++){
        fout << v[i] << ' ';
    }
    return 0;
}
