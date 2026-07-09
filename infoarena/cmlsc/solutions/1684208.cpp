#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{
    int m,n,i,j,y,poz,x,v[1024],v1[1024],k=0;
    f>>m>>n;
    for(i=1;i<=m;i++)
        f>>v[i];
        poz=1;
        y=257;
    for(i=1;i<=n;i++)
    {
        f>>x;
        for(j=poz;j<=m;j++)
        if(y!=v[j])
        if(x==v[j])
        {
            y=v[j];
            k=k+1;
            v1[k]=x;
            poz=j;
        }


    }
    g<<k<<endl;
    for(i=1;i<=k;i++)
        g<<v1[i]<<"  ";
    f.close();
    g.close();
    return 0;
}
