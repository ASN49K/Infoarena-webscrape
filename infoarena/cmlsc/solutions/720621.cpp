#include <fstream>
//#include <algorithm>
using namespace std;
ifstream d("cmlsc.in"); ofstream o("cmlsc.out");
int m,n,i,j;
int a[1025],b[1025];
int c[1026][1026];
void out(int x,int y)
  {
    if (x>0&&y>0)
      {if (a[x]==b[y])
        {
          out(x-1,y-1);
          o<<a[x]<<' ';
        }
        else if (y<x) out(x-1,y);
               else out(x,y-1);}
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