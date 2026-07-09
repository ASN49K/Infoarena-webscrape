#include <fstream>
#define MAX 1025

using namespace std;

int a[MAX], b[MAX], c[MAX], d[MAX][MAX], n, m, k;

void citire ()
{
    scanf ("%d %d\n", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf ("%d ", &a[i]);
    scanf ("\n");
    for (int j = 1; j <= m; j++)
        scanf ("%d ", &b[j]);
}

void constr ()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j])
                d[i][j] = d[i - 1][j - 1] + 1;
            else
                d[i][j] = (d[i - 1][j] > d[i][j - 1]) ? d[i - 1][j] : d[i][j - 1];
}

void subsir ()
{
    for (int i = n, j = m; i > 0;)
        if (a[i] == b[j])
        {
            c[k++] = a[i];
            i--;
            j--;
        }
        else
            if (d[i - 1][j] < d[i][j - 1])
                j--;
            else
                i--;
}

void afisare ()
{
    printf ("%d\n", k);
    for (int i = k - 1; i >= 0; i--)
        printf ("%d ", c[i]);
}

int main()
{
    freopen ("cmlsc.in", "r", stdin);
    freopen ("cmlsc.out", "w", stdout);
    citire ();
    constr ();
    subsir ();
    afisare ();
    return 0;
}
