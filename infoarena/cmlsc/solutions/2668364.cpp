#include <fstream>

using namespace std;

int a[1025][1025], x[1025],y[1025],sol[1025],m,n;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

void cmlsc()
{
    int i, j;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(x[i]==y[j]) a[i][j]=a[i-1][j-1]+1;
            else a[i][j]=max(a[i-1][j], a[i][j-1]);
}

int main()
{
    int i, j, l;
    f>>n>>m;
    for(i=1; i<=n; i++) f>>x[i];
    for(j=1; j<=m; j++) f>>y[j];

    cmlsc();

    g<<a[n][m]<<'\n';
    l=a[n][m];
    i=n;
    j=m;
    while (l)
        if(x[i]==y[j])
        {
            sol[l]=x[i]; l--;
            i--; j--;
        }
        else if(a[i-1][j]>a[i][j-1])  i--;
        else j--;

    for(i=1; i<=a[n][m]; i++) g<<sol[i]<<' ';

    g.close();
    return 0;
}
