#include<fstream>
#define maxm 1025
#define max(x,y) (x)>(y)?(x):(y)
using namespace std;
int a[maxm],b[maxm],d[maxm];
int c[maxm][maxm];
int i,j;
int n,m;
int lin,col;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{
f>>n>>m;
for(i=1;i<=n;i++) f>>a[i];
for(j=1;j<=m;j++) f>>b[j];
for(i=1;i<=n;i++)
 for(j=1;j<=m;j++)
  if(a[i]==b[j])
    c[i][j]=1+c[i-1][j-1];
   else c[i][j]=max(c[i-1][j],c[i][j-1]);
lin=n;col=m;
i=0;
while(c[lin][col])
{if(a[lin]==b[col])
  {i++;
   d[i]=a[lin];
   lin--;col--;
  }
  else if(c[lin][col]==c[lin][col-1]) col--;
   else if(c[lin][col]==c[lin-1][col]) lin--;
}

g<<c[n][m]<<'\n';
for(j=i;j>=1;j--) g<<d[j]<<" ";
g<<'\n';
return 0;
}
