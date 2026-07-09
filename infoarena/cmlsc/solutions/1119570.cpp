#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main()
{
    int m,n,a[1024],b[1024],i,j,k,d,c[1024];
    f>>m>>n; k=0; d=0;
    for(i=0;i<m;i++)
        f>>a[i];
    for(i=0;i<n;i++)
        f>>b[i];
    i=0; j=0;
    while(i<m)
    {while(j<n)
    {
        if(a[i]==b[j])
            {
                c[k]=a[i];
                k++; d=j; i++;
            }
       j++;
    }
    i++; j=++d;}
    for(i=0;i<k;i++)
        g<<c[i];
    f.close();
    g.close();
    return 0;
}
