#include <iostream>
#include <fstream>
#define NMax 1025
#define maxim(a, b) ((a > b) ? a : b)

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[NMax], b[NMax], d[NMax][NMax], nr, sir[NMax];

int main()
{
    int n, m;
    f>>n>>m;
    for (int i = 1; i <= n; ++i)
        f>>a[i];
    for (int i = 1; i <= m; ++i)
        f>>b[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i] == b[j])
                d[i][j] = 1 + d[i - 1][j - 1];
            else
                d[i][j] = maxim(d[i - 1][j], d[i][j - 1]);
    for (int i = n, j = m; i;)
        if (a[i] == b[j])
        {
            sir[++nr] = a[i];
            --i;
            --j;
        }
        else
            if (d[i - 1][j] < d[i][j - 1])
                --j;
            else
                --i;
    g<<nr<<'\n';
    for (int i = nr; i; i--)
        g<<sir[i]<<" ";
    return 0;
}
