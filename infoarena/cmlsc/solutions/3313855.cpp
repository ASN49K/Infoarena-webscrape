#include<fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
short a[1025][1025],b[1024],c[1024],d[1024];
int main()
{
    short k=0,m,n;
    cin>>m>>n;
    for(short i=0;i<m;cin>>b[i++]);
    for(short i=0;i<n;cin>>c[i++]);
    for(short i=1;i<=m;++i)
        for(short j=1;j<=n;a[i][j]=b[i-1]==c[j-1]?a[i-1][j-1]+1:max(a[i-1][j],a[i][j-1]),++j);
    for(;n&&m;)
        if(b[m-1]==c[n-1])
            d[k++]=b[--m],--n;
        else
            a[m-1][n]<a[m][n-1]?--n:--m;
    for(cout<<k<<'\n';k;cout<<d[--k]<<' ');
    return 0;
}
