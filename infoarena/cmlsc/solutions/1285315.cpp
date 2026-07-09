#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int m,n,a[30],b[30],c[30],j,i;
    f>>m>>n;
    for(i=1;i<=m;i++)
    f>>a[i];
    for(j=1;j<=n;j++)
    f>>b[i];
    j=1;
    for(i=1;i<=m;i++)
        for(i=1;i<=n;i++)
        if(a[i]==b[i])
    {
        c[j]=a[i];
        j++;
    }

    g<<j<<endl;
    for(i=1;i<=j;i++)
        g<<c[j]<<" ";
    f.close();
    g.close();
}


