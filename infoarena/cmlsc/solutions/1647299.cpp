#include<stdio.h>
using namespace std;
const int N = 1025;
int a[N], b[N], d[N][N], sol[N];
bool maxim (int a, int b)
{
    if (a > b)
        return a;
    return b;
}
int main ()
{
    FILE *in, *out;
    in = fopen ("cmlsc.in", "r");
    out = fopen ("cmlsc.out", "w");
    int m, n;
    fscanf (in, "%d%d", &n, &m);
    int i;
    for (i = 1; i <= n; i++)
        fscanf (in, "%d", &a[i]);
    for (i = 1; i <= m; i++)
        fscanf (in, "%d", &b[i]);
    int nr = 0, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
                d[i][j] = d[i - 1][j - 1] + 1;
            else
                d[i][j] = maxim (d[i - 1][j], d[i][j - 1]);
        }
    i = n; j = m;
    while (i > 0 && j > 0)
    {
        if (a[i] == b[j])
        {
            sol[++nr] = a[i];
            i--;
            j--;
        }
        else
        {
            if (d[i - 1][j] < d[i][j - 1])
                j--;
            else
                i--;
        }
    }
    fprintf (out, "%d\n", nr);
    for (i = 1; i <= nr; i++)
        fprintf (out, "%d ", sol[i]);
    return 0;
}
