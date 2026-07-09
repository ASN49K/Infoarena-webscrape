#include <iostream>
#include <fstream>
#define dim 1025
using namespace std;
int l[dim][dim];
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{
    int m,n,i,j,a[dim],b[dim],k=0,c[dim];
    f>>n>>m;
    for(i=1;i<=n;++i)
    {
        f>>a[i];
    }
    for(i=1;i<=m;++i)
    {
        f>>b[i];
    }
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;++j)
        {
            if(a[i]==b[j])
                l[i][j]=l[i-1][j-1]+1;
            else
                l[i][j]=max(l[i-1][j],l[i][j-1]);
        }
    }
    g<<l[n][m]<<"\n";
    i=n,j=m;
    while(i>0)
    {
        if(a[i]==b[j])
        {
            c[k++]=a[i];
            i--;j--;
        }
        else
        {
         if(l[i][j-1]>l[i-1][j])
                j--;
         else
                i--;
        }
    }
     for(i=k-1;i>=0;i--)
    {
        g<<c[i]<<" ";
    }
    return 0;
}
