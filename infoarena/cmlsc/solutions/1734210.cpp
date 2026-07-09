#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[1050],b[1050],i,j,m,n,t,d[1050];

int main()
{ f>>n>>m;
  for(i=1;i<=n;i++)
    f>>a[i];

  for(i=1;i<=m;i++)
        f>>b[i];
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if(a[i]==b[j] && b[j]>=0)
  {
      t++;
      d[t]=a[i];
      b[i]=-1;
  }
g<<t<<'\n';
for(i=1;i<=t;i++)
    g<<d[i]<<" ";
    return 0;
}
