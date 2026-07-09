#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],v[1025][1025],c[1025];
int i,j,n,m;
int max(int x,int y)
{
    if(x>y) return x;
    return y;
}
int main()
{

    f>>n>>m;
    for(i=1;i<=n;++i)
        f>>a[i];
    for(j=1;j<=m;++j)
        f>>b[j];

    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(a[i]==b[j])
                v[i][j]=v[i-1][j-1]+1;
    else v[i][j]=max(v[i][j-1],v[i-1][j]);

    g<<v[n][m]<<"\n";
    i=n,j=m;
    int k=0;
    while(i!=0 && j!=0)
    {
        if(a[i]==b[j])
            {
                k++;
                c[k]=b[j];
                i--;j--;
            }
        else if(v[i-1][j]>v[i][j-1]) i--;
        else j--;
    }
    for(i=k;i>=1;--i)
        g<<c[i]<<" ";
    return 0;
}
