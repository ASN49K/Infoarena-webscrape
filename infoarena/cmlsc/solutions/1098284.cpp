#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int aux,a[1025],b[1025],z[1025],m,n,i,j,x;
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>m>>n;
    for(i=1;i<=m;i++)
         f>>a[i];
    for(i=1;i<=n;i++)
         f>>b[i];
    x=0;
    for(i=1;i<=m;i++)
         for(j=1;j<=n;j++)
                   if(a[i]==b[j]) {x++;z[x]=a[i];}
    g<<x<<'\n';
    for (i=1;i<=x;i++)
    {
        g<<z[i]<<" ";
    }
    return 0;
}
