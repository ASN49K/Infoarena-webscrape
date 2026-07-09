#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025][1025],b[1025],c[1025],d[750],i,j,k,l,o,m,n;

int main()
{
 f>>n>>m;
 for(i=1;i<=n;i++) f>>b[i];
 for(j=1;j<=m;j++) f>>c[j];

 for(i=1;i<=n;i++)
 {
     for(j=1;j<=m;j++)
     {
         if(b[i]==c[j]) a[i][j]=a[i-1][j-1]+1;
         else a[i][j]=max(a[i-1][j],a[i][j-1]);
     }
 }

 i=n;j=n;
    while(i&&j)
        {
          if(b[i]==c[j])
           {
               d[0]++;
               d[d[0]]=b[i];
               i--; j--;
           }
           else if(a[i-1][j]>a[i][j-1]) i--;
           else j--;
        }

 g<<a[n][m]<<"\n";

 for(i=d[0];i>=1;i--)
 g<<d[i]<<" ";

 return 0;
}
