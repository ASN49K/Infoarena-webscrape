/// Cel mai lung subsir comun infoarena

#include <fstream>
#include <vector>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1025][1025];
vector<int> cmlsc;

void determinareSir(int n, int m, int a[], int b[])
{
    if (a[1] == b[1])
    {
        dp[1][1] = 1;
        cmlsc.push_back(a[1]);
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
            if (cmlsc.size() < size_t(dp[1][j]))
            {
                cmlsc.push_back(a[1]);
            }
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
            if (cmlsc.size() < size_t(dp[i][1]))
            {
                cmlsc.push_back(a[i]);
            }
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
                if (cmlsc.size() < size_t(dp[i][j]))
                {
                    cmlsc.push_back(a[i]);
                }
            }
            else
            {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    fout << dp[m][n] << '\n';
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

    determinareSir(n, m, a, b);
    for (int val : cmlsc)
    {
        fout << val << ' ';
    }
    fout.close();

    return 0;
}
