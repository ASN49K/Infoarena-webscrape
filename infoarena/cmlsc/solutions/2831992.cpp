#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMAX = 1025;
int n, m, a[NMAX], b[NMAX], dp[NMAX][NMAX], ans[NMAX];

void read()
{
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        fin >> a[i];
    }
    for (int j = 1; j <= m; j++)
    {
        fin >> b[j];
    }
}

void cmlsc()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
}

void afisare()
{
    int cnt = 1;
    int i, j;
    for (i = n, j = m; i > 0;)
    {
        
        if (a[i] == b[j])
        {
            ans[cnt] = a[i];
            cnt++;
            i--;
            j--;
        }
        else if (dp[i-1][j] < dp[i][j-1])
            j--;
        else i--;
         
    }
    cnt--;
    fout << cnt << '\n';
    for (int i = cnt; i >= 1; i--)
    {
        fout << ans[i] << ' ';
    }
}

int main()
{
    read();
    cmlsc();
    afisare();
}