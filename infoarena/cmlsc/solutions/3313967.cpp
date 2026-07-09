#include<fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
short a[1024],b[1024],c[1025][1025],d[1024];
int main()
{
    int k=0,m,n;
    cin>>n>>m;
    for(int i=0;i<n;cin>>a[i++]);
    for(int i=0;i<m;cin>>b[i++]);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;c[i][j]=a[i-1]==b[j-1]?c[i-1][j-1]+1:max(c[i-1][j],c[i][j-1]),++j);
    for(;n;a[n-1]==b[m-1]?d[k++]=a[--n],--m:c[n-1][m]<c[n][m-1]?--m:--n);
    for(cout<<k<<'\n';k;cout<<d[--k]<<' ');
    return 0;
}
