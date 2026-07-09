#include <fstream>
using namespace std;

ifstream f ("input.in");
ofstream g ("output.out");

int a[1025], b[1025], c[1025][1025], d[1025], m, n;

void citire();
void lcs();
void afisare();
void bk();

int main()
{
    citire();
    lcs();
    afisare();
    return 0;
}

void citire()
{
    f>>n>>m;
    for (int i=1; i<=n; ++i)
        f>>a[i];
    for (int j=1; j<=m; ++j)
        f>>b[j];
}

void afisare()
{
    g<<c[n][m]<<'\n';
    for (int i=1; i<=c[n][m]; ++i)
        g<<d[i]<<" ";
}

void lcs()
{
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            if (a[i]==b[j])
                c[i][j] = c[i-1][j-1] + 1;
            else if (c[i-1][j]<c[i][j-1])
                c[i][j] = c[i][j-1];
            else c[i][j] = c[i-1][j];
    int mx = c[n][m];
    for (int i=n, j=m; i>0 && j>0;)
        if (a[i]==b[j])
        {
            d[mx]=a[i];
            mx--;
            i--;
            j--;
        }
        else if (c[i][j-1]<c[i-1][j])
            i--;
        else j--;
}

