#include <fstream>
#include <iostream>
using namespace std;

int i,k=1,j;

int main()
{
    int v,y;
    int a[256];
    int b[256];
    int c[256];

    ifstream f("cmlsc.in");
    ifstream g("cmlsc.out");
    f>>v>>y;

    for(i=1;i<=v;i++)
        f>>a[i];
    for(i=1;i<=y;i++)
        f>>b[i];

    for(i=1;i<=v;i++)
        for(j=1;j<=y;j++)
            if(a[i]==b[j]) c[k++]=a[i];
    k--;
    g<<k<<"\n";
    for(i=1;i<=k;i++)
        g<<c[i]<<" ";

    return 0;
}
