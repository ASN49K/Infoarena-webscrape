#include <fstream>
using namespace std;
ifstream f("clmsc.in");
ofstream g("clmsc.out");
int m,n,i,j,a[1025][1025],x[1025],y[1025];
int main()
{ f>>n>>m;
for(i=1;i<=n;++i)
    f>>x[i];
for(i=1;i<=m;++i)
    f>>y[i];
for(i=n;i>=1;--i)
    for(j=m;j>=1;--j)
      if(x[i]==y[j])
        a[i][j]=a[i+1][j+1]+1;
else
    if(a[i+1][j]>a[i][j+1])
     a[i][j]=a[i+1][j];
else
    a[i][j]=a[i][j+1];
g<<a[1][1]<<'\n';
i=1;
j=1;
while(i<=n&&j<=m)
{if(x[i]==y[j])
 {g<<x[i]<<' ';
  i++;
  j++;}
  else
    if(a[i+1][j]==a[i][j])
     i++;
  else
    j++;}


    return 0;
}
