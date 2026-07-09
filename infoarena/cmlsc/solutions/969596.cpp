#include <fstream>
using namespace std;

short n, m, a[260], b[260], c[260], d[260][260], k, i, j;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main() {
    f>>n>>m;
    for (i=1; i<=n; ++i)
        f>>a[i];
    for (j=1; j<=m; ++j)
        f>>b[j];
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            if (a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else {
                if (d[i][j-1]>d[i-1][j])
                    d[i][j]=d[i][j-1];
                else
                    d[i][j]=d[i-1][j];
            }
    for (i=n, j=m; i; )
        if (a[i]==b[j]) {
            c[++k]=a[i];
            i--;
            j--;
        }
        else {
            if (d[i][j-1]>d[i-1][j])
                j--;
            else
                i--;
        }
    g<<k<<'\n';
    for (i=k; i>=1; --i)
        g<<c[i]<<' ';
    return 0;
}

