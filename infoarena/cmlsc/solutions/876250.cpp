#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int i,n,x[1025][1025],j,m,nr;
char a[1025],b[1025],sir[1025];
int main()
{ f>>n>>m;
  for(i=1;i<=n;++i) f>>a[i];
  for(j=1;j<=m;++j) f>>b[j];
  for(i=1;i<=n;++i) for(j=1;j<=m;++j) { if(a[i]==b[j]) x[i][j]=1+x[i-1][j];
                                        else x[i][j]=max(x[i-1][j],x[i][j-1]);
                                       }
  for(i=1;i<=n;++i) { for(j=1;j<=m;++j) g<<x[i][j]<<" ";
                      g<<'\n';
                     }  
  i=n;
  j=m;
  while(i&&j) { if(a[i]==b[j]) sir[++nr]=a[i],--i,--j;
		        else if(x[i-1][j]<x[i][j-1]) --j;
		        else --i;
			   }
  g<<nr<<'\n';
  for(i=nr;i;--i) g<<sir[i]<<" ";
  return 0;
}
