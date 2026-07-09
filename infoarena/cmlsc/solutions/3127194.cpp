#include <iostream>
#include <fstream>
using namespace std;
using llx = long long;

ifstream fin("alfa.in");
ofstream fout("alfa.out");

#define LGMAX 1024

int dp[LGMAX+1][LGMAX+1];
// dp[i][j] = lungimea celui mai lung subsir comun al prefixelor a[1...i] si b[1...j]
int a[LGMAX+1], b[LGMAX+1], sol[LGMAX+1];

int main()
{
    int n, m, i, j, lg_sol;

    fin >> m >> n;
    for (i = 1; i<=m; i++)
        fin >> a[i];
    for (i = 1; i<=n; i++)
        fin >> b[i];

    for (i = 1; i<=m; i++)
        for (j = 1; j<=n; j++)
        {
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
        
    lg_sol = 0;
    i = m;
    j = n;

    while (i > 0 && j > 0)
    {
        if (a[i] == b[j])
        {
            sol[++lg_sol] = a[i];
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    fout << lg_sol << '\n';
    for (i = lg_sol; i>=1; i--)
        fout << sol[i] << ' ';
    return 0;
}