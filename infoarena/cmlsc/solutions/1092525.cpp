#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1025],b[1025],c[1025][1025],i,j,xi,yi,k,l,x[1025];

int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++) f>>a[i];
    for(j=1;j<=m;j++) f>>b[j];

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
    }
    xi=1; yi=1;
    for(k=1;k<=c[n][m];k++)
    {
        for(i=xi;i<=n;i++)
          for(j=yi;j<=m;j++)
            if(c[i][j]==k)
              if(a[i]==b[j])
                 {
                    x[k]=a[i];
                    xi=i+1; yi=j+1;
                    i=n+1; j=m+1;
                 }
    }

     g<<c[n][m]<<"\n";

    for(i=1;i<=c[n][m];i++)
    g<<x[i]<<" ";

    return 0;
}
