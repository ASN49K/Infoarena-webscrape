#include <fstream>
#define N 1030
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,k,L,a[N],b[N],c[N],d[N][N];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)f>>a[i];
    for(i=1;i<=m;i++)f>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
                else
                if(d[i-1][j]>d[i][j-1])
                    d[i][j]=d[i-1][j];
                    else
                    d[i][j]=d[i][j-1];
        }
    L=d[n][m];
    g<<L<<'\n';
    for(i=n,j=m,k=L;d[i][j];)
    {
        if(a[i]==b[j])
        {
            c[k]=a[i];i--;j--;k--;
        }
        else
            if(d[i][j]==d[i-1][j])i--;
            else j--;
    }
    for(i=1;i<=L;i++)g<<c[i]<<' ';
    return 0;
}
