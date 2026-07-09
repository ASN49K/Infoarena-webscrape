#include <fstream>

#define MAXN 1102

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[MAXN][MAXN];
int v[MAXN];
int x[MAXN], n, m;

inline void Read()
{
    fin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        fin >> v[i];
    }
    for (int i = 1; i <= m; i++)
        fin >> x[i];
}

inline void afisare(int i, int j)
{
    if (i >= 1 && j >= 1)
    {
        if (v[i] == x[j])
        {
            afisare(i - 1, j - 1);
            fout << v[i] << " ";
        }
        else
        {
            if (a[i - 1][j] > a[i][j - 1])
            {
                afisare(i - 1, j);
            }
            else
                afisare(i, j - 1);
        }
    }
}

inline void cmlsc()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (v[i] == x[j])
            {
                a[i][j] = a[i - 1][j - 1] + 1;
            }
            else
            {
                if (a[i - 1][j] > a[i][j - 1])
                    a[i][j] = a[i - 1][j];
                else
                    a[i][j] = a[i][j - 1];
            }
        }
    }

    fout << a[n][m] << "\n";

    afisare(n, m);
}

int main ()
{
    Read();
    cmlsc();

    fin.close(); fout.close(); return 0;
}
