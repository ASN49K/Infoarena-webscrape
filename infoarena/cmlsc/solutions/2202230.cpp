#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025], b[1025], cm[1025][1025], n, m;

void ReadFunction();
void Cmlsc();

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
    int x = 1;
    for (int j = 1; j <= m; ++j)
        if (cm[n][j] == x)
        {
            x++;
            fout << b[j] << ' ';
        }
}
