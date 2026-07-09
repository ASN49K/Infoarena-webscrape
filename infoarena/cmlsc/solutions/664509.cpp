#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1030],b[1030],d[1030][1030],n,m,sir[1030],i,j;
void afis()
{
int x,y,k,i;
y=m;x=n;
for (k=d[n][m];k>0;)
{
if (a[x]==b[y])
{
sir[k]=a[x];
x--;
y--;
k--;
}
else
if (d[x-1][y]==k)
x--;
else
y--;
}
for (i=1;i<=d[n][m];i++)
g<<sir[i]<<' ';
}
int main()
{
 f>>n>>m;
   for (i=1;i<=n;i++) f>>a[i];
   for (i=1;i<=m;i++) f>>b[i];
 
   for (i=1; i<=n;i++)
      for (j=1; j<=m; j++)
        if (a[i]==b[j]) d[i][j]=1+d[i-1][j-1];
          else d[i][j]=max(d[i-1][j],d[i][j-1]);
g<<d[n][m]<<'\n';
afis();
return 0;
}
