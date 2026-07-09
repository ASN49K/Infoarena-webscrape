#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,l;
int sol[1025],a[1025],b[1025],c[1025][1025];
int main()
{
    f>>n>>m;
    for (i=1;i<=n;i++)
        f>>a[i];
    for (i=1;i<=m;i++)
        f>>b[i];
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
    g<<c[n][m]<<'\n';
    i=n;j=m;
    l=1;
    while(i&&j)
    {
        if (a[i]==b[j])
            {
                sol[l++]=a[i];
                i--;
                j--;
            }
        else if (c[i-1][j]<c[i][j-1]) j--;
                else i--;
    }
    for (i=l-1;i>=1;i--)
        g<<sol[i]<<' ';
    g<<'\n';
    return 0;
}
