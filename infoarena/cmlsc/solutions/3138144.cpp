#include<fstream>
using namespace std;
ifstream F("cmlsc.in");
ofstream G("cmlsc.out");
short s[1025][1025],a[1024],b[1024],i,j,k,v[1024],n,m;
int main()
{
    for(F>>n>>m;i<n;F>>a[i++]);
    for(i=0;i<m;F>>b[i++]);
    for(i=1;i<=n;++i)
        for(j=1;j<=m;s[i][j]=max<short>(s[i-1][j-1]+(a[i-1]==b[j-1]),max(s[i-1][j],s[i][j-1])),++j);
    for(;n;a[n-1]==b[m-1]?v[k++]=a[--n],--m:s[n-1][m]<s[n][m-1]?--m:--n);
    for(G<<k<<'\n';k;G<<v[--k]<<' ');
    return 0;
}
