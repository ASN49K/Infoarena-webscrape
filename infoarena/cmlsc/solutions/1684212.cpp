#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{
    int m,n,i,j,poz,x,v[1024],v1[1024],k=0;
    f>>m>>n;
    for(i=1;i<=m;i++)
        f>>v[i];
    for(i=1;i<=n;i++)
    {
        f>>x;
        for(j=1;j<=m;j++)
        if(x==v[j])
        {
            k=k+1;
            v1[k]=x;
        }


    }
    g<<k<<endl;
    for(i=1;i<=k;i++)
        g<<v1[i]<<"  ";
    f.close();
    g.close();
    return 0;
}
