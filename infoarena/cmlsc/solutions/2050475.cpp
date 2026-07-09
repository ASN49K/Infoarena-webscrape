#include <fstream>
#define maxim(a, b) a > b ? a : b

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

void citire();
void dinamica();

int n, m;
int d[1030][1030];
int a[1030], b[1030], sol[1030];

int main()
{
    citire();
    dinamica();
    return 0;
}

void citire()
{
    fin >> n >> m;

    for (int i = 1; i <= n; i++)
        fin >> a[i];

    for (int i = 1; i <= m; i++)
        fin >> b[i];
}

void dinamica()
{
    d[1][1] = (a[1] == b[1]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
                continue;

            if (a[i] == b[j])
                d[i][j] = 1 + d[i - 1][j - 1];
            else
                d[i][j] = maxim(d[i - 1][j], d[i][j - 1]);
        }

    int i = n, j = m;
    while (i >= 1 && j >= 1)
    {
        if (a[i] == b[j])
        {
            sol[++sol[0]] = a[i];
            i--;
            j--;
        }
        else
        {
            if (d[i - 1][j] > d[i][j - 1])
                i--;
            else
                j--;
        }
    }

    fout << d[n][m] << '\n';
    for (int i = d[n][m]; i; i--)
        fout << sol[i] << ' ';
    fout << '\n';
}
