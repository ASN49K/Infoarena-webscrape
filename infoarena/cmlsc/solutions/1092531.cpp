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
    xi=n; yi=m;

     while(xi>1||yi>1)
     {
         if(xi>1) while(xi>1&&c[xi][yi]==c[xi-1][yi]) xi--;
         if(yi>1) while(yi>1&&c[xi][yi]==c[xi][yi-1]) yi--;
         x[c[xi][yi]]=a[xi];
         if(xi>1) xi--;
         if(yi>1) yi--;
     }

     g<<c[n][m]<<"\n";

    for(i=1;i<=c[n][m];i++)
    g<<x[i]<<" ";

    return 0;
}
