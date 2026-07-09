#include <iostream>
#include <fstream>
#define N 1025
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[N], b[N];
int dp[N][N], sol[N];

int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    for(int j = 1; j <= m; j++)
       fin >> b[j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <=m; j++)
            if(a[i]==b[j])
                dp[i][j] = dp[i - 1][j - 1]  + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    fout << dp[n][m] << '\n';
    int i = n;
    int j = m;
    int cnt = 0;
    while(i > 0 && j > 0)
    {
        if(a[i] == b[j])
        {
            sol[++cnt] = a[i];
            i--;
            j--;
        }
        else
        {
            if(dp[i][j-1] > dp[i-1][j])
                j--;
            else
                i--;
        }
    }
    for(int i = cnt; i >= 1; i--)
        fout << sol[i] << " ";
    return 0;
}
