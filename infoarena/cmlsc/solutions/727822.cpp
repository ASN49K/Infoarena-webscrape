#include <fstream>
#include <algorithm>
using namespace std;
ifstream d("cmlsc.in"); ofstream o("cmlsc.out");
int m,n,i,j;
int a[1100],b[1100];
int c[1100][1100];
void out(int x,int y)
  {
	while (c[x][y]==c[x-1][y]) x--;
	while (c[x][y]==c[x][y-1]) y--;
	if (c[x][y]!=1) out(x-1,y-1);
	o<<a[x]<<' ';
  }
int main()
  {
    d>>n>>m;
    for (i=1;i<=n;i++) d>>a[i];
    for (j=1;j<=m;j++) d>>b[j];
    for (i=1;i<=n;i++)
      for(j=1;j<=m;j++)
          if (a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
    o<<c[n][m]<<'\n';
    out(n,m);
  }