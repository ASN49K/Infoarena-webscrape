#include <fstream>
#define max(a, b) ((a > b) ? a : b)
#define NMax 1024
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m,n,a[NMax],b[NMax],d[NMax][NMax],sir[NMax],bst;
int main(void)
{
    int i, j;
    f>>m>>n;
    for (int i=1; i<=m; i++)
        f>>a[i];
    for (int i=1; i<=n; i++)
        f>>b[i];
    for(int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            if (a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    for (i = m, j = n; i; )
        if (a[i] == b[j])
            sir[++bst] = a[i], --i, --j;
        else if (d[i-1][j] < d[i][j-1])
            --j;
        else
            --i;
    g<<bst<<'\n';
    for (i=bst; i>=1; i--)
        g<<sir[i]<<' ';

    return 0;
}
