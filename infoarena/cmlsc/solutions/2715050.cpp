#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream o("cmlsc.out");
int main()
{
    int m, n;
    f >> m >> n;
    int a[m + 1], b[n + 1], lsc[m + 1][n + 1];
    for (int i = 1; i <= m; i++)
    {
        f >> a[i];
        lsc[i][0] = 0;
    }
    for (int j = 1; j <= n; j++)
    {
        f >> b[j];
        lsc[0][j] = 0;
    }
    lsc[0][0] = 0;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            if (a[i] == b[j])
                lsc[i][j] = lsc[i - 1][j - 1] + 1;
            else
                lsc[i][j] = max(lsc[i][j - 1], lsc[i - 1][j]);
        }

    int sir[min(m, n)], len = 0;
    for (int i = m, j = n; i && j;)
    {
        if (a[i] == b[j])
        {
            sir[len] = a[i];
            len++;
            i--;
            j--;
        }
        else if (lsc[i][j] == lsc[i][j - 1])
        {
            j--;
        }
        else
            i--;
    }

    o << len << "\n";
    for (int i = len - 1; i >= 0; i--)
        o << sir[i] << " ";
}