#include<fstream>
using namespace std;
ifstream F("cmlsc.in");
ofstream G("cmlsc.out");
short i,n,m,x[1024],y[1024],s[1025][1025],j,k,v[1024];
int main()
{
    for(F>>n>>m;i<n;F>>x[i++]);
    for(i=0;i<m;F>>y[i++]);
    for(i=1;i<=n;++i)
        for(j=1;j<=m;s[i][j]=max<short>(s[i-1][j-1]+(x[i-1]==y[j-1]),max(s[i-1][j],s[i][j-1])),++j);
    for(;n;x[n-1]==y[m-1]?v[k++]=x[--n],--m:s[n-1][m]<s[n][m-1]?--m:--n);
    for(G<<k<<'\n';k;G<<v[--k]<<' ');
    return 0;
}
