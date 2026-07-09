#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[257],b[257];
int main()
{
    int i,j,n,m,nr=0;
    f>>n;
    f>>m;
    for(i=1;i<=n;i++)
    f>>a[i];
    for(j=1;j<=m;j++)
    f>>b[j];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
         if(a[i]==b[j])
            {
             nr++;
             g<<a[i]<<" ";
            }
    }
    g<<"\n";
    g<<nr;
    return 0;
}
