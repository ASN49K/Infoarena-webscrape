#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, i, j, nr, r1, a[1024], b[1024], rez[1024], best[1024][1024];

int main () {

    fin >> n >> m;
    for (i = 1; i <= n; i++)
        fin >> a[i];
    for (j = 1; j <= m; j++)
        fin >> b[j];

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
                best[i][j] = best[i-1][j-1] + 1;

            else
                best[i][j] = max(best[i-1][j], best[i][j-1]);
        }

    nr = 0;
    i = n;  j = m;
    while (i != 0 && j != 0)
    {
        if (a[i] == b[j])   {   nr++;   rez[nr] = a[i];     i--;    j--;    }

        else if (best[i-1][j] >= best[i][j-1])   i--;
        else    j--;
    }

    fout << nr << "\n";
    for (i = nr; i >= 1; i--)
        fout << rez[i] << " ";
}
