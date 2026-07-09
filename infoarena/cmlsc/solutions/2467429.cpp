#include <fstream>

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
    int n,m,x[1024],y[1024],a[1024][1024]={0};
    f>>n>>m;
    citire(x,n);
    citire(y,m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
    {
        if(x[i-1]==y[j-1])
            a[i][j]=a[i-1][j-1]+1;
        else
            a[i][j]=max(a[i-1][j],a[i][j-1]);
    }
    g<<a[n][m]<<'\n';
    int v[1024],k=0;
    for(int i=n,j=m;i;)
    {
        if(x[i-1]==y[j-1])
            v[k++]=x[i-1],--i,--j;
        else if(a[i-1][j]<a[i][j-1])
            --j;
        else
            --i;
    }
    for(int i=k-1;i>=0;--i)
        g<<v[i]<<' ';
    return 0;
}
