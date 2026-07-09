#include <iostream>
#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,i,a[1024],b[1024],j,c[1024],k;
int main()
{
    f>>n>>m;
    for(i=0;i<n;i++)
    {
        f>>a[i];
    }
    for(i=0;i<m;i++)
    {
        f>>b[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i]==b[j]) c[k++]=a[i];
        }
    }
    g<<k<<'\n';
    for(i=0;i<k;i++)
    {
        g<<c[i]<<' ';
    }
    g<<'\n';
    return 0;
    f.close();
    g.close();
}
