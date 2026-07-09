#include <fstream>

#define max(a,b) a>b ? a:b

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

void citire(int *v,int n)
{
    for(int i=0;i<n;++i)
        f>>v[i];
}

int main()
{
    int n,m,a[1024],b[1024],d[1024][1024]={0};
    f>>n>>m;
    citire(a,n);
    citire(b,m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
    {
        if(a[i-1]==b[j-1])
            d[i][j]=d[i-1][j-1]+1;
        else
            d[i][j]=max(d[i-1][j],d[i][j-1]);
    }
    g<<d[n][m]<<'\n';
    int k=0,v[1024];
    for(int i=n,j=m;j;)
    {
        if(a[i-1]==b[j-1])
            v[k++]=a[i-1],--i,--j;
        else if(d[i-1][j]<d[i][j-1])
            --j;
        else
            --i;
    }
    for(int i=k-1;i>=0;--i)
        g<<v[i]<<' ';
    return 0;
}
