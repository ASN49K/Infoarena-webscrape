#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, N[1025];
int m, M[1025];
int pd[1025][1025]; // pd[i][j] - c.m.l.s.c daca luam primele i elemente din N si primele j elemente din M
int l, rasp[1025];

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i) { fin >> N[i]; }
    for (int i = 1; i <= m; ++i) { fin >> M[i]; }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (N[i] == M[j])
            {
                pd[i][j] = pd[i - 1][j - 1] + 1;

                if (pd[i][j] > l)
                {
                    rasp[++l] = M[j];
                }
            }
            else
            {
                pd[i][j] = max(pd[i - 1][j], pd[i][j - 1]);
            }
        }
    }

    fout << pd[n][m] << '\n';
    for (int i = 1; i <= l; ++i)
    {
        fout << rasp[i] << ' ';
    }

    fin.close();
    fout.close();
    return 0;
}
