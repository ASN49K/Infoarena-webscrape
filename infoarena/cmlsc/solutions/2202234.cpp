#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025], b[1025], cm[1025][1025], n, m;

void ReadFunction();
void Cmlsc();
void AfisSol(int i, int j, int x);

int main()
{
    ReadFunction();
    Cmlsc();
}

void ReadFunction()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
    for (int i = 1; i <= m; ++i)
        fin >> b[i];
}

void Cmlsc()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
    {
        if (a[i] == b[j])
            cm[i][j] = cm[i - 1][j - 1] + 1;
        else
        {
            cm[i][j] = max(cm[i][j - 1], cm[i - 1][j]);
        }
    }
    fout << cm[n][m] << '\n';
    int x = cm[n][m];
    AfisSol(n, m, x);
}

void AfisSol(int i, int j, int x)
{
    if (x == 0)
        return;
    if (a[i] == b[j])
    {
        AfisSol(i - 1, j - 1, x - 1);
        fout << a[i] << ' ';
        return;
    }
    if (cm[i - 1][j] > cm[i][j - 1])
    {
        AfisSol(i - 1, j, x);
        return;
    }
    AfisSol(i, j - 1, x);
}
