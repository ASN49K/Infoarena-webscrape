#include <iostream>
#include <fstream>
#define DM 1030
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, a[DM], b[DM], dp[DM][DM], rez[DM], nr;

int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    for(int i = 1; i <= m; i++)
        fin >> b[i];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            /// dp[i][j] reprezinta cmlsc dintre a[1...i-1] si b[1...j-1]. Daca a[i] si b[j] sunt egale atunci se mareste cu 1
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    int i = n, j = m;
    while(i > 0 && j > 0)
    {
        if(a[i] == b[j]) // le adaugam la solutie
        {
            rez[++nr] = a[i];
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j] > dp[i][j-1])
                i--;
            else j--;
        }

    }
    cout << dp[n][m] << '\n';
    for(int i = nr; i >= 1; i--)
        cout << rez[i] << ' ';
    return 0;
}

