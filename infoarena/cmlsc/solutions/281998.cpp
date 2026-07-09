#include <fstream>
using namespace std;
int main()
{
    int m,n,a[2000],b[2000],sir[2000],i,j,max=0;
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>m>>n;
    for(i=1;i<=m;i++)
     f>>a[i];
    for(i=1;i<=n;i++)
     f>>b[i];
    for(i=1;i<=m;i++)
     for(j=1;j<=n;j++)
      if(a[i]==b[j])
       sir[++max]=a[i];
    g<<max<<"\n";
    for(i=1;i<=max;i++)
      g<<sir[i]<<" ";
    g<<"\n";
    f.close();
    g.close();
    return 0;
}
