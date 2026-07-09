#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream o("cmlsc.out");

int max(int a, int b)
{
    return a < b ? b : a;
}

int main()
{

    int m, n, aux;
    f >> m >> n;
    int a[m], b[n];
    int lcs[m + 1][n + 1];
    for (int i = 0; i < m; i++)
    {
        f >> a[i];
        lcs[i][0] = 0;
    }
    lcs[m][0] = 0;
    lcs[0][n] = 0;
    for (int i = 0; i < n; i++)
    {
        f >> b[i];
        lcs[0][i] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
            else
                lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
        }
    }

    int len = 0, sir[1024];
    for (int i = m, j = n; i > 0 && j > 0;)
    {
        if (a[i - 1] == b[j - 1])
        {
            sir[len] = a[i - 1];
            len++;
            i--;
            j--;
        }
        else
        {
            if (lcs[i][j] == lcs[i][j - 1])
            {
                j--;
            }
            else
                i--;
        }
    }

    o << lcs[m][n] << "\n";
    for (int i = len - 1; i >= 0; i--)
        o << sir[i] << " ";
}