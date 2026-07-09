#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1200],b[1200],c[1200][1200],i,j,n,m,k,d[1200];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;i<=m;i++)
        f>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(a[i]==b[j])
            c[i][j]=c[i-1][j-1]+1;
        else c[i][j]=max(c[i-1][j],c[i][j-1]);
    }
    g<<c[n][m]<<'\n';
    i=n;
    j=m;
    while(i&&j)
    {

        if(c[i][j]>max(c[i-1][j],c[i][j-1]))
        {
            d[++k]=a[i];
            i--;
            j--;
        }
        else if(c[i-1][j]>c[i][j-1])i--;
        else j--;
    }
    while(k--)
        g<<d[k+1]<<' ';
    return 0;
}
