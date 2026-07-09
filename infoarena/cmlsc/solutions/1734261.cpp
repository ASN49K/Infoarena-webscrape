#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1050],b[1050],o[1050],m,n,i,j,t;

int main()
{f>>n>>m;
 for(i=1;i<=n;i++)
    f>>a[i];
 for(i=1;i<=m;i++)
    f>>b[i];

 for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if(a[i]==b[j] && a[i]>=0)
 {
  o[++t]=a[i];

a[i]=-3;

 }
    g<<t<<'\n';
    for(i=1;i<=t;i++)
        g<<o[i]<<" ";
    return 0;
}
