#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m, n, a[1030], b[1030], d[1030][1030], sir[1030], stefan, i, j;
int main()
{
    f>>m>>n;
    for(i=1; i<=m; i++)
        f>>a[i];
    for(i=1; i<=n; i++)
        f>>b[i];
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j], d[i][j-1]);
    for(i=m, j=n; i;)
        if(a[i]==b[j])
            sir[++stefan]=a[i], i--, j--;
        else if(d[i-1][j]<d[i][j-1])
            j--;
        else  i--;
    g<<stefan<<'\n';
    for(i=stefan; i>=1; i--)
        g<<sir[i]<<' ';
    return 0;
}
