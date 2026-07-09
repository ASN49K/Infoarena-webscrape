#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[1025], b[1025], x[1025][1025];

void afisare(int i, int j)
{
    if (i>=1 && j>=1)
    {
        if (a[j] == b[i])
            afisare(i-1, j-1), fout << a[j] << " ";

        else if (x[i-1][j] > x[i][j-1])
            afisare(i-1, j);

        else
            afisare(i, j-1);
    }
}

int main()
{
    fin >> n >> m;

    for (int i=1; i<=n; i++)
        fin >> a[i];

    for (int i=1; i<=m; i++)
        fin >> b[i];

    for (int i=1; i<=m; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (a[j] == b[i])
                x[i][j] = x[i-1][j-1]+1;
            else
                x[i][j] = max(x[i-1][j], x[i][j-1]);
        }
    }

    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i==0)
                fout << a[j] << " ";

            else if (j==0)
                fout << b[i] << " ";

            else
                fout << x[i][j] << " ";
        }

        fout << "\n";
    }

    fout << x[m][n] << "\n";

    afisare(m, n);

    return 0;
}
