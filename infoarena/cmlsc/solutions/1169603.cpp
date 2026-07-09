#include <fstream>
using namespace std;

short a[1027], b[1027], i, j, n, m, sir[1027], M[1027][1027];

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main()
{
    f>>n>>m;
    for (i=1; i<=n; ++i)
        f>>a[i];
    for (i=1; i<=m; ++i)
        f>>b[i];
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            if (a[i]==b[j])
                M[i][j]=M[i-1][j-1]+1;
            else
                M[i][j]=max(M[i-1][j], M[i][j-1]);
    i=n;
    j=m;
    short nr=0;
    while (i>0 && j>0)
        if (a[i]==b[j]) {
            sir[++nr]=a[i];
            --i;
            --j;
        }
        else {
            if (M[i-1][j]>M[i][j-1])
                --i;
            else
                --j;
        }
    g<<nr<<'\n';
    for (i=nr; i; --i)
        g<<sir[i]<<' ';
    return 0;
}
