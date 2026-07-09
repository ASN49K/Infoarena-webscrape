#include <bits/stdc++.h>
#define oo 1000000007
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m, a[1025], b[1025];
int dp[1025][1025];
/**
0 1 7 3 9 8
7 0 1 0 0 0
5 0
8
*/
void drum(int i, int j)
{
    if(i < 1 && j < 1) return;
    if(a[i] == b[j])
    {
        drum(i - 1, j - 1);
        cout << a[i] << " ";
    }
    else
    {
        if(dp[i - 1][j] > dp[i][j - 1])
            drum(i  - 1, j);
        else drum(i, j - 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fout.tie(0);
    int i,j;
    fin >> n >> m;
    for(i = 1; i <= n; i++)
        fin >> a[i];
    for(i = 1; i <= m; i++)
        fin >> b[i];
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    fout << dp[n][m] << "\n";
    drum(n,m);
    return 0;
}
