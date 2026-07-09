#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
short int m,lu,n,l[1024][1024],i,j,a[1024],b[1024],sir[1024];

int max(int a,int b)
{
  if (a>b) return a;
  else return b;
}
void citire()
{
  f>>n>>m;
  for (i=1;i<=n;i++) f>>a[i];
  for (j=1;j<=m;j++) f>>b[j];
}
void detlung( )
{
  for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
      if (a[i]==b[j]) l[i][j]=l[i-1][j-1]+1;
      else l[i][j]=max(l[i-1][j],l[i][j-1]);
      g<<l[n][m]<<'\n';
}
void reconst()
{
   while (l[n][m])
   {
     if (a[n]==b[m]) sir[++lu]=a[n],n--,m--;
     else if (l[n-1][m]<l[n][m-1]) m--;
          else n--;
   }
   for (i=lu;i>=1;i--) g<<sir[i]<<' ';
}
int main()
{
    citire( );
    detlung( );
    reconst( );
    return 0;
}
