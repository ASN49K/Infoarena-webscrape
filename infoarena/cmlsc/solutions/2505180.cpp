#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main()
{
    int m,n,a[1025],b[1025],v[1025],z[1025],ga=0,p,k,cb,max1=-1,i,j,l;
    f>>m>>n;
    for(i=1;i<=m;i++)
        f>>a[i];
    for(j=1;j<=n;j++)
        f>>b[j];
    for(l=1;l<=m;l++)
    {
        cb=1; k=0;
        for(i=l;i<=m;i++)
        {
            j=cb; ga=0;
            while(j<=n&&ga==0)
                if(a[i]==b[j])
                {
                    k++;
                    v[k]=a[i];
                    ga=1;
                }
                else j++;
            if(ga==1) cb=j;
        }
        if(k>max1)
        {
            max1=k;
            for(p=1;p<=k;p++)
                z[p]=v[p];
        }
        for(p=1;p<=k;p++)
            v[p]=0;
    }
    g<<max1<<'\n';
    for(p=1;p<=max1;p++)
        g<<z[p]<<' ';
    return 0;
}
