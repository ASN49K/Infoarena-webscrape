#include <bits/stdc++.h>
#define mx 1030
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[mx], b[mx], ans[mx], dp[mx][mx], l, n, m, i, j, x, y;

int main()
{
    fin >> n >> m;
    for(int i=1; i<=n; i++)
        fin >> a[i];
    for(int i=1; i<=m; i++)
        fin >> b[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i] == b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    x = n, y = m;
    while(x!=0 and y!=0)
    {
        if(a[x]==b[y])
        {
            ans[++l]=a[x];
            x--,y--;
        }
        else if(dp[x-1][y] > dp[x][y-1]) x--;
        else y--;
    }
    fout << l << '\n';
    for(; l; l--)
        fout << ans[l] << " ";
    return 0;
}
