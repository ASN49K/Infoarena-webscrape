#include <fstream>
#define nmax 1025
#include <algorithm>
using namespace std;
int i,j,n,m,nr,x[nmax],a[nmax],b[nmax],d[nmax][nmax];
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n;
    f>>m;
    for (i=1; i<=n; i++) f>>a[i];
    for (j=1; j<=m; j++) f>>b[j];
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            if (a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i][j-1],d[i-1][j]);
    i=n;
    j=m;
    while (i>0 && j>0)
        if (a[i]==b[j])
        {
            nr++;
            x[nr]=a[i];
            i--;
            j--;
        }
        else if (d[i-1][j]<d[i][j-1])
            j--;
        else
            i--;
    reverse(x+1,x+nr+1);
    g<<nr<<'\n';
    for (i=1; i<=nr; i++) g<<x[i]<<" ";
    f.close();
    g.close();
    return 0;
}
