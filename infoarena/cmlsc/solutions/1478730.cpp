#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

 int m,n,i,j,k,l,a[1024],aa[1024],v1[1024],v2[1024];

int main()
{
     int lg, lgg=0;
    f>>m>>n;
    for( i=1;i<=m;i++)f>>v1[i];
    for( i=1;i<=n;i++)f>>v2[i];
    for(i=1;i<=m;i++)
    {k=1; lg=0;
    for(l=i;l<=m;l++)
    for(j=k;j<=n;j++)if(v1[l]==v2[j]){ lg++;
                                        a[lg]=v1[l];
                                        k=j+1;
                                        break;}
         if(lgg<lg){for(int q=1;q<=lg;q++)aa[q]=a[q];lgg=lg;}
    }
    g<<lgg<<endl;
    for( i=1;i<=lgg;i++) g<<aa[i]<<" ";
    g.close();
    f.close();
}
