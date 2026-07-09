#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main()
{
    int m,n,a[1025],b[1025],i,j,k,d,c[1025];
    f>>m>>n; k=0; d=0;
    for(i=1;i<=m;i++)
        f>>a[i];
    for(i=1;i<=n;i++)
        f>>b[i];
    i=0; j=0;
    while(i<=m)
    {while(j<=n)
    {
        if(a[i]==b[j])
            {
                c[k]=a[i];
                k++; d=j; i++;
            }
       j++;
    }
    i++; j=++d;}
    g<<k;
    for(i=1;i<=k;i++)
        g<<c[i];
    f.close();
    g.close();
    return 0;
}
