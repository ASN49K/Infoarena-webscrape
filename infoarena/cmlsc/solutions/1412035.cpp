#include <fstream>
#include <algorithm>
#define NMAX 1030

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int mat[NMAX][NMAX], v[NMAX], x[NMAX], i, j, n, m, sol[NMAX], cont=0;

int main()
{
    f>>n>>m;
    for (i=1; i<=n; ++i) f>>v[i];
    for (j=1; j<=m; ++j) f>>x[j];

    for (i=1; i<=n; ++i)
    for (j=1; j<=m; ++j)
    if (v[i]==x[j])
    mat[i][j]=mat[i-1][j-1]+1;
    else
    mat[i][j]=max(mat[i-1][j],mat[i][j-1]);

    g<<mat[n][m]<<'\n';

    for (i=n, j=m; i>=1 && j>=1;)
    if (v[i]==x[j])
    {
        sol[++cont]=v[i];
        i--;
        j--;
    }
    else
    if (mat[i-1][j]>mat[i][j-1])
    i--;
    else
    j--;

    for (i=cont; i>=1; --i)
    g<<sol[i]<<" ";

    return 0;
}
