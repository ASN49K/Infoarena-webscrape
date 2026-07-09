#include <iostream>
#include <fstream>
#include <cmath>
#include <stack>
#define DM 1024
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int dp[DM][DM], n, m, v1[DM], v2[DM], rez[DM];
void din()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(v1[i]==v2[j])
                dp[i][j] = max(dp[i - 1][j], max(dp[i - 1][j - 1] + 1, dp[i][j - 1]));
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
}
int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> v1[i];
    for(int i = 1; i <= m; i++)
        fin >> v2[i];
    din();
    fout << dp[n][m] << '\n';
    int cn = n, cm = m, cnt = 0;
    while(cn != 0 && cm != 0)
    {
        if(v1[cn] == v2[cm])
            rez[++cnt] = v1[cn], cm--, cn--;
        else if(dp[cn-1][cm] < dp[cn][cm-1])
            cm--;
        else
            cn--;
    }
    for(int i = cnt; i >= 1; i--)
       fout << rez[i] << " ";
    return 0;
}
