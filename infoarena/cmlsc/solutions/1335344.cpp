#include <iostream>
#include <fstream>
using namespace std;
ifstream f("livada.in");
ofstream g("livada.out");
int v[1000001];
int main()
{
    int i,m,n,j,k=0,maj,nr,randuri=0,maxpom=0,pom=0,p;
    f>>m;
    f>>n;
    f>>p;
    for(i=1;i<=m;i++)
    {
      nr=0;
      for(j=1;j<=n;j++)
          f>>v[j];
      for(j=1;j<=n;j++)

          if(k==0)
          {
              k=1;
              maj=v[j];
          }
          else
            if(maj==v[j])
             k++;
            else
             k--;

     for(j=1;j<=n;j++)
      {
          if(maj==v[j])
            nr++;
      }
      if(nr>=n/2+1)
          randuri++;

      for(j=1;j<=n;j++)

        if(v[j]==v[j+1])
           pom++;
        else
           if(pom>maxpom)
            {
             maxpom=pom;
              pom=0;
            }

      }

g<<randuri;
g<<"\n";
g<<maxpom;
    return 0;
}
