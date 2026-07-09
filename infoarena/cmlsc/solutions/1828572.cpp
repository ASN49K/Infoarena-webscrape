#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,k,x[1030],y[1030],z[1030],a[1030][1030];
int main()
{
    f>>n>>m;
    for(i=1; i<=n; i++)
        f>>x[i];
    for(j=1; j<=m; j++)
        f>>y[j];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(x[i]==y[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=max(a[i][j-1],a[i-1][j]);
    g<<a[n][m]<<'\n';
    for(i=n,j=m; a[i][j];)
        if(x[i]==y[j])
        {
            k++;
            z[k]=x[i];
            i--;
            j--;
        }
        else if(a[i][j-1]>=a[i-1][j])
            j--;
        else
            i--;
    for(i=k;i>=1;i--)
        g<<z[i]<<' ' ;
    return 0;
}
