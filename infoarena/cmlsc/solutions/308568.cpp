#include <fstream>
using namespace std;
ofstream ofis("cmlsc.out");
ifstream ifis("cmlsc.in");
long n,m,a[1909],b[1523],i,j,d[1034][1930],sir[1234],lmax;
long maxim(long, long);

int main()
{
    ifis>>n>>m;
    for (i=1; i<=n; i++)
    ifis>>a[i];
    for (i=1; i<=m; i++)
    ifis>>b[i];
    
    for (i=1; i<=n; i++)
    for (j=1; j<=m; j++)
    if (a[i]==b[j]) d[i][j]=1+d[i-1][j-1];
    else d[i][j]=maxim(d[i-1][j],d[i][j-1]);
    
    for (i=n, j=m; i; )
    if (a[i]==b[j]) {sir[++lmax]=a[i]; --i; --j;}
    else if (d[i-1][j]<d[i][j-1]) --j;
    else --i;
    
    ofis<<lmax<<"\n";
    for (i=lmax; i>=1; i--)
    ofis<<sir[i]<<" ";
    return 0;
}

long maxim(long x, long y)
{
     if (x<=y) return y;
     return x;
}
    
