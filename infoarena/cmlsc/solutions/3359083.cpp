/// Cel mai lung subsir comun infoarena

#include <fstream>
#include <vector>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1025][1025];
vector<int> cmlsc;

void construireDp(int m, int a[], int n,  int b[])
{
    if (a[1] == b[1])
    {
        dp[1][1] = 1;
    }
    else
    {
        dp[1][1] = 0;
    }

    for (int j = 2; j <= n; j++)
    {
        if (a[1] == b[j])
        {
            dp[1][j] = 1;
        }
        else
        {
            dp[1][j] = dp[1][j-1];
        }
    }
    for (int i = 2; i <= m; i++)
    {
        if (a[i] == b[1])
        {
            dp[i][1] = 1;
        }
        else
        {
            dp[i][1] = dp[i-1][1];
        }
    }

    for (int i = 2; i <= m; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            if (a[i] == b[j])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
}

void afisareSir(int m, int a[], int n,  int b[])
{
    int i = m, j  = n;
    while (i && j)
    {
        if (a[i] == b[j])
        {
            cmlsc.push_back(a[i]);
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    for (int i = cmlsc.size()-1; i >= 0; i--)
    {
        fout << cmlsc.at(i) << ' ';
    }
}

int main()
{
    int m, n, a[1025], b[1025];
    fin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        fin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        fin >> b[i];
    }
    fin.close();

    construireDp(m, a, n, b);

    fout << dp[m][n] << '\n';
    afisareSir(m, a, n, b);
    fout.close();

    return 0;
}
