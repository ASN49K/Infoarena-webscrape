#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,nr,m,a[1000],b[1000],c[1000],d[1000][1000];
int main()
{
    int i,j;
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;i<=m;i++)
        f>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
          if(a[i]==b[j])
            d[i][j]=d[i-1][j-1]+1;
          else
            d[i][j]=max(d[i-1][j],d[i][j-1]);
    g<<d[n][m]<<"\n";
    i=n; j=m;
    while(i!=0 && j!=0)
    {
        if(a[i]==b[j])
        {
            nr++;
            c[nr]=a[i];
            i--; j--;
        }
        else
            if(d[i-1][j]>d[i][j-1])
               i--;
             else
               j--;
    }
    for(i=nr;i>=1;i--)
        g<<c[i]<<" ";

    return 0;
}
