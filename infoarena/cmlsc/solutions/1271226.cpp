#include <iostream>
#include <fstream>

using namespace std;

int a[1026][1026];

int main()
{
    int m, n, i, j, l = 0, LCS[1025];
    ifstream f;
    ofstream g;

    f.open("cmlsc.in");

    f >> m >> n;
    for (i = 0, j = 2; j <= m + 1; j++)
    {
        f >> a[i][j];
    }
    for (i = 2, j = 0; i <= n + 1; i++)
    {
        f >> a[i][j];
    }

    f.close();

    for (i = 2; i <= n + 1; i++)
    {
        for (j = 2; j <= m + 1; j++)
        {
            if (a[i][j-1] > a[i-1][j])
            {
                a[i][j] = a[i][j-1];
            }
            else
            {
                a[i][j] = a[i-1][j];
            }

            if (a[0][j] == a[i][0])
            {
                a[i][j]++;
            }
        }
    }

    for (i = n + 1, j = m + 1; i > 1 && j > 1; )
    {
        if (a[i][j-1] == a[i-1][j] && a[i][j-1] <= a[i-1][j-1])
        {
            if (a[i][0] == a[0][j])
            {
                l++;
                LCS[l] = a[0][j];
            }
            i--;
            j--;
        }
        else if (a[i][j-1] > a[i-1][j])
        {
            j--;
        }
        else
        {
            i--;
        }
    }

    g.open("cmlsc.out");

    g << l << '\n';
    for (; l > 0; l--)
    {
        g << LCS[l] << ' ';
    }

    g.close();

    return 0;
}
