#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int a[1025], b[1025], cm[1025][1025], n, m;

void citire()
{
    in>>n>>m;
    for(int i=1;i<=n;i++)
        in>>a[i];
    for(int i=1;i<=m;i++)
        in>>b[i];
}

void AfisSol(int i, int j, int x)
{
    if (x == 0)
        return;
    if (a[i] == b[j])
    {
        AfisSol(i - 1, j - 1, x - 1);
        out << a[i] << ' ';
        return;
    }
    if (cm[i - 1][j] > cm[i][j - 1])
    {
        AfisSol(i - 1, j, x);
        return;
    }
    AfisSol(i, j - 1, x);
}
void cmlsc()
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
    out << cm[n][m] << '\n';
    int x = cm[n][m];
    AfisSol(n, m, x);
}
int main()
{
    citire();
    cmlsc();

    return 0;
}
