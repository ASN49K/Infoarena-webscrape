#include<fstream>
#define X 1020
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int i,j,n,m,a[X],b[X],D[X][X],S[X];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;++i) f>>a[i];
    for(i=1;i<=m;++i) f>>b[i];
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j) D[i][j]=(a[i]==b[j]?1+D[i-1][j-1]:max(D[i-1][j],D[i][j-1]));
    for(i=n,j=m;i;)
        if(a[i]==b[j]) S[++S[0]]=a[i];
        else D[i-1][j]<D[i][j-1]?--j:--i;
    g<<S[0]<<'\n';
    for(i=S[0];i;--i) g<<S[i]<<" ";
    return 0;
}
