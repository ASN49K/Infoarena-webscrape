#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1030],b[1030],i,j,fin[1000],fn,max1;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
      f>>a[i];
    for(j=1;j<=m;j++)
      f>>b[j];
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
    max1=0;
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
        if(a[i]==b[j])
        {
            max1++;
            fn++;
            fin[fn]=a[i];
        }
    g<<max1<<"\n";
    for(i=1;i<=max1;i++)
      g<<fin[i]<<" ";
    return 0;
}
