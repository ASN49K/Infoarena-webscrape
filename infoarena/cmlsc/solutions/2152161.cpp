#include <fstream>
#include <algorithm>

using namespace std;

FILE*fin=fopen ("cmlsc.in", "r");
FILE*fout=fopen ("cmlsc.out", "w");

int main ()
{
    int m, n, maxi=0, i, v[1025], w[1025], poz, pozfin;
    fscanf (fin, "%d", &m);
    fscanf (fin, "%d", &n);
    for (i=1; i<=m; i++)
        fscanf (fin, "%d", &v[i]);
    for (i=1; i<=n; i++)
        fscanf (fin, "%d", &w[i]);
    sort (v+1, v+m+1);
    sort (w+1, w+n+1);
    for (i=1; i<=max(n, m); i++)
        if (v[i]==w[i])
        {
            poz=i;
            i=1025;
        }
    for (i=poz; i<=min(n, m); i++)
    {
        maxi++;
        if (v[i]!=w[i])
        {
            pozfin=i;
            i=1025;
        }
    }
    fprintf (fout, "%d", maxi);
    fprintf (fout, "%c", '\n');
    for (i=poz; i<=pozfin; i++)
    {
        fprintf (fout, "%d", v[i]);
        fprintf (fout, "%c", ' ');
    }
    return 0;
}
