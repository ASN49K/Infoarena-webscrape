#include <fstream>

using namespace std;

FILE*fin=fopen ("flip.in", "r");
FILE*fout=fopen ("flip.out", "w");

int cmmdc (int x, int y)
{
    int r=x%y;
    while (r)
    {
        x=y;
        y=r;
        r=x%y;
    }
    return y;
}

int main ()
{
    int n, m;
    fscanf (fin, "%d", &n);
    fscanf (fin, "%d", &m);
    int a[n+1][m+1], i, j;
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            fscanf (fin, "%d", &a[i][j]);
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
        {

        }
    return 0;
}
