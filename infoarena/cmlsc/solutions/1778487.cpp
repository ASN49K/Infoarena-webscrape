#include <fstream>

using namespace std;

ifstream f("sircomun.in");
ofstream g("sircomun.out");

int m, n, a[1001], b[1001], d[1001][1001], sir[1001],bst;

int main()
{  int i, j;
f>>m>>n;
  for(i=1;i<=m;i++)
    f>>a[i];
  for(i=1;i<=n;i++)
    f>>b[i];
  for(i=1;i<=m;i++)
    for(j=1;j<=m;j++)
      if(a[i]==b[j])
      d[i][j]=1+d[i-1][j-1];
  else
      d[i][j]=max(d[i-1][j],d[i][j-1]);

   for(i=m,j=n;i>=1;)
     if(a[i]==b[j])
       sir[++bst]=a[i],--i,--j;
   else if(d[i-1][j]<d[i][j-1])
      --j;
     else
        --i;
     g<<bst<<'\n';
     for(i=bst;i>=1;i--)
        g<<sir[i]<<' ';

    return 0;
}
