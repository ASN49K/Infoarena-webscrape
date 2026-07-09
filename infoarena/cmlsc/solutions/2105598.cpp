#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,x[1025],a[1025][1025],ma,y[1025],sol[1025];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>x[i];
    for(j=1;j<=m;j++)
        f>>y[j];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(x[i]==y[j])
            a[i][j]=a[i-1][j-1]+1;
        else a[i][j]=max(a[i-1][j],a[i][j-1]);
    }
    g<<a[n][m]<<'\n';
    int k=a[n][m];
    i=n;j=m;
    while(i+j>2)
    {
        if(x[i]==y[j])
        {
            sol[k--]=x[i];
            i--;j--;
        }
        else
        {
            if(a[i-1][j]>a[i][j-1])
                i--;
            else j--;
        }
    }
    for(i=1;i<=a[n][m];i++)
        g<<sol[i]<<" ";
    return 0;
}
