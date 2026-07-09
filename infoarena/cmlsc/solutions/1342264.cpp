#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],v[1025][1025];
int max(int x,int y)
{
    if(x>y) return x;
    return y;
}
int main()
{
    int i,j,n,m,c[1025],k=0;
    f>>n>>m;
    for(i=1;i<=n;++i)
        f>>a[i];
    for(j=1;j<=m;++j)
        f>>b[j];
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
        if(a[i]==b[j])
            {
                v[i][j]=v[i-1][j-1]+1;
                k++;
                c[k]=a[i];
            }
    else v[i][j]=max(v[i][j-1],v[i-1][j]);
    g<<v[n][m]<<"\n";
    for(int l=1;l<=k;++l)
        g<<c[l]<<" ";
    return 0;
}
