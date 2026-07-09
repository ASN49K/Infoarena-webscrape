#include <fstream>

using namespace std;

FILE*fin=fopen ("cmlsc.in", "r");
FILE*fout=fopen ("cmlsc.out", "w");

int i, j, v[1025], w[1025], a[1025][1025], sf[1025], bst;

int main ()
{
    int m, n;
    fscanf (fin, "%d", &m);
    fscanf (fin, "%d", &n);
    for (i=1; i<=m; i++)
        fscanf (fin, "%d", &v[i]);
    for (j=1; j<=n; j++)
        fscanf (fin, "%d", &w[i]);
    for (i=1; i<=m; i++)
        for (j=1; j<=n; j++)
            if (v[i]==w[j])
                a[i][j]=1+a[i-1][j-1];
            else
                a[i][j]=max(a[i-1][j], a[i][j-1]);
    for (i=m, j=n; i; )
        if (v[i]==w[j])
        {
            sf[bst]=v[i];
            i--;
            j--;
            bst++;
        }
    fprintf (fout, "%d\n", bst);
    for (i=bst; i; i--)
        fprintf (fout, "%d ", sf[i]);
    fprintf (fout, "%c", '\n');
    fflush;
    return 0;
}
