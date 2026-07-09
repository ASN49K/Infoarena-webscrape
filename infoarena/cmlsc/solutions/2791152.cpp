#include <fstream>
#define NMAX 1025
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[NMAX], b[NMAX], dp[NMAX][NMAX], sol[NMAX], i, j, k, lga, lgb;

int main()
{
    f >> lga >> lgb;
    for (i = 1; i <= lga; ++i) f >> a[i];
    for (j = 1; j <= lgb; ++j) f >> b[j];

    for (i = 1; i <= lga; ++i)
         for (j = 1; j <= lgb; ++j)
              if (a[i] == b[j])
                  dp[i][j] = dp[i - 1][j - 1] + 1;
                  else
                  dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

    i = lga, j = lgb;
    while (dp[i][j])
    {
        if (a[i] != b[j])
        {
            if (dp[i - 1][j] < dp[i][j - 1])
                --j;
                else
                --i;
        }
        else
        sol[++k] = a[i], --i, --j;
    }
    ++i, ++j;

    g << k << '\n';
    while (k)
    {
        g << sol[k] << " ";
        --k;
    }

    return 0;
}
