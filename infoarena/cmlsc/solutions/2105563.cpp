#include <fstream>
#define maxim(a, b) ((a>b) ? a : b)

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, i, j, a[1030], b[1030], d[1030][1030], bst, sir[1030];

int main()
{
    f>>n>>m;
    for(i=1; i<=n; i++)
        f>>a[i];
    for(i=1; i<=m; i++)
        f>>b[i];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]==b[j])
                d[i][j] = d[i-1][j-1]+1;
            else d[i][j] = maxim(d[i-1][j], d[i][j-1]);
    for(i=n, j=m; i; )
        if(a[i]==b[j])
            sir[++bst] = a[i], i--, j--;
        else if(d[i-1][j]<d[i][j-1]) j--;
        else i--;
    g<<bst<<'\n';
    for(i=bst; i; i--)
        g<<sir[i]<<' ';
    return 0;
}
