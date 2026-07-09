#include <fstream>
#define lim 1030
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[lim],b[lim],c[lim][lim],d[lim],k,row,col;
int main()
{
    f>>n>>m;
    for (int i=1;i<=n;i++) f>>a[i];
    for (int i=1;i<=m;i++) f>>b[i];
    for (int i=0;i<=m;i++)
        for (int j=0;j<=n;j++)
            if (i==0 || j==0) c[i][j]=0;
            else if (b[i]==a[j]) c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
    row=m;
    col=n;
    while (row>=1 && col>=1)
        if (b[row]==a[col])
        {
            k++;
            d[k]=b[row];
            row--;
            col--;
        }
        else if (c[row-1][col]>c[row][col-1]) row--;
        else col--;
    g<<k<<'\n';
    for (int i=k;i>=1;i--) g<<d[i]<<' ';
    f.close();
    g.close();
    return 0;
}
