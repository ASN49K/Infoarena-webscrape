#include <fstream>
#define maxn 1030
using namespace std;
ifstream f("secvmin.in");
ofstream g("secvmin.out");
int m,n,a[maxn],b[maxn],d[maxn][maxn],s[maxn];
int main()
{
    int i=0, j=0, k=0;
    f>>m>>n;
    for (i=1;i<=m;i++)
        f>>a[i];
    for (i=1;i<=n;i++)
        f>>b[i];
    for (i=1; i <= m; i++)
        for (j=1; j <= n; j++)
            if (a[i] == b[j])
               d[i][j] = d[i-1][j-1] + 1;
            else
            if (d[i-1][j] > d[i][j-1])
               d[i][j] = d[i-1][j];
            else
                d[i][j] = d[i][j-1];
    g<<d[i][j]<<endl;
return 0;
}
