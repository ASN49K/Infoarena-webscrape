#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main()
{
    int m,n,a[1024],b[1024],v[1024],z[1024],p,k=0,cb,max1=-1,i,j,l;
    f>>m>>n;
    for(i=1;i<=m;i++)
        f>>a[i];
    for(j=1;j<=n;j++)
        f>>b[j];
    cb=1;
    for(l=1;l<=m;l++)
    {
        for(i=l;i<=m;i++)
            for(j=cb;j<=n;j++)
                if(a[i]==b[j])
                {
                    v[k]=a[i];
                    cb=j;
                    k++;
                }
        if(k>max1)
        {
            max1=k;
            for(p=0;p<k;p++)
                z[p]=v[p];

        }
        k=0; cb=1;
        for(p=0;p<k;p++)
            v[p]=0;
    }
    g<<max1<<'\n';
    for(p=0;p<max1;p++)
        g<<z[p]<<' ';
    return 0;
}
