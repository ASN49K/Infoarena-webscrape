#include <fstream>
#define maxim(x,y) ((x>y)?x:y)
using namespace std;
int d[1025],mat[1025][1025],k,a[1025],b[1025],n,m;
void drum(int i,int j)
{
  if(a[i]==b[j]) { d[++k]=a[i]; if(i-1 and j-1)drum(i-1,j-1); } else
  if((mat[i-1][j]>mat[i][j-1]) and (i-1)) drum(i-1,j); else if (j-1) drum(i,j-1);
}
int main()
{
  int i,j;
  ifstream fi("cmlsc.in");
  ofstream fo("cmlsc.out");
  fi>>n>>m;
  for(i=1;i<=n;i++) fi>>a[i];
  for(i=1;i<=m;i++) fi>>b[i];
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
      if(a[i]==b[j]) mat[i][j]=mat[i-1][j-1]+1; else mat[i][j]=maxim(mat[i-1][j],mat[i][j-1]);
  fo<<mat[n][m]<<"\n";
  drum(n,m);
  for(i=k;i>0;i--) fo<<d[i]<<" ";
  fo.close();
}
