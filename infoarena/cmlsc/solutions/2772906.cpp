#include <iostream>
#include <fstream>
#define MAXN 1024
#define VERT 1
#define DIAG 2
#define ORIZ 3
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

short x[MAXN + 1], y[MAXN + 1], rasp[MAXN + 1], v[MAXN + 1], drum[MAXN + 2][MAXN + 2], m, n, ans, cur;

int main ()
{
    fin >> m >> n;
    for (int i = 1; i <= m; i++)
        fin >> x[i];
    for (int i = 1; i <= n; i++)
        fin >> y[i];

    for (int i = 1; i <= m; i++)
    {
        ans = v[0];
        for (int j = 1; j <= n; j++)
        {
            cur = v[j];
            if (x[i] == y[j])
            {
                drum[i][j] = DIAG;
                v[j] = ans + 1;
            }
            else if (v[j - 1] <= v[j])
                    drum[i][j] = VERT;
            else
            {
                drum[i][j] = ORIZ;
                v[j] = v[j - 1];
            }
            ans = cur;
        }
    }
    fout << v[n] << endl;

    int i = m, j = n, k = 0;

    while (i != 0 && j != 0)
    {
        if (drum[i][j] == DIAG)
            rasp[k++] = x[i], i--, j--;
        else if (drum[i][j] == VERT)
            i--;
        else j--;
    }

    for (i = k - 1; i >= 0; i--)
        fout << rasp[i] << " ";

    fin.close();
    fout.close();
    return 0;
}
