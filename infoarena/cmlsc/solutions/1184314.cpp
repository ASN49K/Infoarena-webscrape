#include <iostream>
#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main()
{
    int v1[257],v3[257], v2[257],i,j,k=0,n,m,a=1;
    f>>n>>m;
   for(i=1;i<=n;i++)
   f>>v1[i];
   for(i=1;i<=m;i++)
   f>>v2[i];

   for(i=1;i<=n;i++)
   {for(j=1;j<=m;j++)
    if(v1[i]==v2[j])
   {k++;v3[a]=v1[i];a++;}
   }
   g<<k<<'\n';
   for(i=1;i<a;i++)
    g<<v3[i]<<" ";
    return 0;
}
