#include <fstream>
#include <algorithm>
using namespace std;
int main ()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int mat[1028][1028],v[1028],x[1028],ans[1028],i,n,j,m,k=0;
    f>>m>>n;
    for (i=1; i<=m; i++) f>>v[i];
    for (i=1; i<=n; i++) f>>x[i];

    for (i=1; i<=m; i++)
    for (j=1; j<=n; j++)
    if (v[i]==x[j])
    mat[i][j]=mat[i-1][j-1]+1;
    else
    mat[i][j]=max(mat[i-1][j],mat[i][j-1]);

    i=m; j=n;

    while (i>0 && j>0)
    if (v[i]==x[j])
    {
        ans[++k]=v[i];
        i--;
        j--;
    }
    else
    if (mat[i-1][j]>mat[i][j-1])
    i--;
    else
    j--;

    g<<k<<'\n';
    for (i=k; i>=1; i--)
    g<<ans[i]<<" ";
    return 0;

}
