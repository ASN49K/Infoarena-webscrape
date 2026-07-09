#include <iostream>
#include <fstream>
using namespace std;

const int MAX_SIZE = 1025;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m, n, a[MAX_SIZE], b[MAX_SIZE], LCS[MAX_SIZE][MAX_SIZE], ans[MAX_SIZE], idx;

int main()
{
    fin >> m >> n;
    for (int i = 0; i < m; i++)
        fin >> a[i];
    for (int i = 0; i < n; i++)
        fin >> b[i];

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (a[i] == b[j])
            {
                LCS[i+1][j+1] = 1 + LCS[i][j];
            }
            else
                LCS[i+1][j+1] = max(LCS[i][j+1], LCS[i+1][j]);
        }
    }

    for (int i = m, j = n; i >= 0 && j >= 0;)
    {
        if (a[i] == b[j])
        {
            ans[++idx] = a[i];
            i--; j--;
        }
        else if (LCS[i][j+1] < LCS[i+1][j])
            --j;
        else
            --i;
    }

    fout << LCS[m][n] << "\n";
    for (int i = idx; i > 1; --i)
        fout << ans[i] << " ";
}
