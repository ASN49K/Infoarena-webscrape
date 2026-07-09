#include <fstream>

using namespace std;

int n,m,a[1025],b[1025],mat[1025][1025],i,j,k,sir[1025];

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n>>m;
    for (i=1;i<=n;i++)
        f>>a[i];
    for (j=1;j<=m;j++)
        f>>b[j];
    for (i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if (a[i]==b[j]) mat[i][j]=1+mat[i-1][j-1];
            else
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
        }
    i=n;j=m;
    k=0;
    while (i>0 && j>0)
        if (a[i]==b[j])
        {
            sir[++k]=a[i];
            i--;
            j--;
        }
        else
            if (mat[i-1][j]<mat[i][j-1]) j--;
                else i--;
    g<<k<<'\n';
    for (i=k;i>=1;i--)
    g<<sir[i]<<" ";
    return 0;
}
