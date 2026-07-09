#include <fstream>
using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
const int nmax=1e3+3;
int n,m,a[nmax],b[nmax],d[nmax][nmax],sol[nmax],k;
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i) f>>a[i];
    for(int i=1;i<=m;++i) f>>b[i];
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            d[i][j]=max(d[i-1][j],d[i][j-1]);
            if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
        }
    }
    g<<d[n][m]<<'\n';
    while(n&&m)
    {
        if(a[n]==b[m])
        {
            sol[++k]=a[n];
            --n;
            --m;
            continue;
        }
        if(d[n-1][m]>d[n][m-1]) --n;
        else --m;
    }
    for(int i=k;i>=1;--i) g<<sol[i]<<' ';
    return 0;
}
