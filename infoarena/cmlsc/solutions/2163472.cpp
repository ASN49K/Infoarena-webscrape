#include <fstream>

using namespace std;

FILE*fin=fopen ("cmlsc.in", "r");
FILE*fout=fopen ("cmlsc.out", "w");

int n, m, a[1024][1024], v[1024], w[1024], i, j, vf[1024], poz=0;

int main ()
{
    fscanf (fin, "%d", &m);
    fscanf (fin, "%d", &n);
    for (i=1; i<=m; i++)
        fscanf (fin, "%d", &v[i]);
    for (i=1; i<=n; i++)
        fscanf (fin, "%d", &w[i]);
    for (i=1; i<=m; i++)
        for (j=1; j<=n; i++)
            if (v[i]==w[j])
                a[i][j]=1+a[i-1][j-1];
            else
                a[i][j]=max(a[i-1][j], a[i][j-1]);
    for (i=m, j=n; i; )
        if (v[i]==w[j])
        {
            vf[++poz]=v[i];
            i--;
            j--;
        }
        else
            if (a[i-1][j]<a[i][j-1])
                j--;
            else
                i--;
    fprintf (fout, "%d", poz);
    for (i=poz; i; i--)
        fprintf (fout, "%d ", vf[i]);
    return 0;
}
