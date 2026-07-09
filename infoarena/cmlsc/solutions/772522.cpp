#include <fstream>

using namespace std;

int main()
{ int n,m,a[1025],b[1025],c[1025],i,j,counter=0;
   ifstream f("cmlsc.in");
   ofstream g("cmlsc.out");
   f>>m>>n;
  for(i=1;i<=m;i++)
    f>>a[i];
    for(i=1;i<=n;i++)
    f>>b[i];
    f.close();
  for(i=1;i<=m;i++)
     for(j=1;j<=n;j++)
   if(a[i]==b[j])
    { counter++;
     c[counter]=a[i];}
     g<<counter<<"\n";
   for(i=1;i<=counter;i++)
     g<<c[i]<<" ";
     g.close();
return 0;
}
