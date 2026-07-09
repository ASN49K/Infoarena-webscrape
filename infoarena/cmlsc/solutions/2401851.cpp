#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,i,j,x;
int b[1025],c[1025], rez[1025];
int a[1025][1025];

int main()
{
    f>>n>>m;
    for (i=1;i<=n;i++)
        f>>b[i];
    for (i=1;i<=m;i++)
        f>>c[i];
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (b[i]==c[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=max(a[i-1][j],a[i][j-1]);
    i=n, j=m;
    while (a[i][j])
    {
        while (a[i][j]==a[i-1][j])
            i--;
        while (a[i][j]==a[i][j-1])
            j--;
        x++;
        rez[x]=b[i];
        i--;
        j--;
    }
    g<<x<<"\n";
    for (i=x;i>=1;i--)
        g<<rez[i]<<" ";
    return 0;
}
