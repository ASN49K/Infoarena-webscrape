#include <iostream>
#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{
    int a[1024],b[1024],i,j,nr=0,p,n,m,c[1024],k=0;
    f>>n>>m;

for(i=1; i<=n; i++)
        f>>a[i];
    for(j=1; j<=m; j++)
        f>>b[j];

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]==b[j])
            {
                nr++;
                c[++k]=a[i];
            }

    g<<nr;
    g<<endl;
    for(i=1; i<=k; i++)
        g<<c[i]<<" ";

    f.close();
    g.close();
}
