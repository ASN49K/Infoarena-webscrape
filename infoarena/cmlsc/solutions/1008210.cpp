#include <iostream>
#include <fstream>
using namespace std;

int main()
{ int m,n,i,j,k,ok;
  long a[1025], b[1025],v[1025];
  fstream f("cmlsc.in",ios::in);
  fstream g("cmlsc.out",ios::out);
  f>>m>>n;
  for(i=1;i<=m;i++) f>>a[i];
  for(i=1;i<=n;i++) f>>b[i];
  k=0;
  for(i=1;i<=m;i++){ ok=1; j=1;
                      while(ok&&j<=n)
                     {
                       if(a[i]==b[j]) { k++; v[k]=a[i]; ok=0;  }
                        j++;}
       }

  g<<k<<endl;
  for(i=1;i<=k;i++)
    g<<v[i]<<" ";
f.close();
g.close();
    return 0;
}
