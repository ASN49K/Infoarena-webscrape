# include <fstream>
# include <algorithm>
# include <vector>
# include <cstring>
# define NR 1025
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int R,i,j,n,m,VV;
int mat[NR][NR], a[NR], b[NR], sol[NR];
int main ()
{
    f>>n>>m;
    for (i=1; i<=n; ++i) f>>a[i];
    for (i=1; i<=m; ++i) f>>b[i];

    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            if (a[i]==b[j]) mat[i][j]=mat[i-1][j-1]+1;
            else mat[i][j]=max(mat[i-1][j], mat[i][j-1]);

    i=n; j=m;
    while (i>0 && j>0)
    {
        if (a[i]==b[j]) sol[++VV]=a[i], --i, --j;
        else {
                 if (mat[i-1][j]>mat[i][j-1]) --i;
                 else --j;
             }
    }
    g<<mat[n][m]<<"\n";
    for (i=VV; i>=1; --i)
        g<<sol[i]<<" ";

    return 0;
}
