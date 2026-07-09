#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,a[1030],b[1030],d[1030][1030],sir[1030],w;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;++i)
        f>>a[i];
    for(i=1;i<=m;++i)
        f>>b[i];
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
    {
        if(a[i]==b[j])
        {
            d[i][j]=1+d[i-1][j-1];
        }
        else
            d[i][j]=max(d[i-1][j],d[i][j-1]);
    }
    i=n;j=m;
    while(i!=0&& j!=0)
    {
        if(a[i]==b[j]){
            sir[++w]=a[i]; --i;--j;}
        else
            if(d[i-1][j]<d[i][j-1])
            --j;
        else
            --i;
    }
    g<<w<<"\n";
    for(i=w;i>=1;--i)
    g<<sir[i]<<" ";
    return 0;
}
