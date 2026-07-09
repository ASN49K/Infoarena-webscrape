#include<fstream>
using namespace std;
ifstream F("cmlsc.in");
ofstream G("cmlsc.out");
short i,n,m,a[1024],b[1024],c[1025][1025],d[1024],j,k;
int main()
{
    for(F>>n>>m;i<n;F>>a[i++]);
    for(i=0;i<m;F>>b[i++]);
    for(i=1;i<=n;++i)
        for(j=1;j<=m;c[i][j]=a[i-1]==b[j-1]?c[i-1][j-1]+1:max(c[i-1][j],c[i][j-1]),++j);
    for(;n;a[n-1]==b[m-1]?d[k++]=a[--n],--m:c[n][m-1]<c[n-1][m]?--n:--m);
    for(G<<k<<'\n';k;G<<d[--k]<<' ');
    return 0;
}
