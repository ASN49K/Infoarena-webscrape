#include<fstream>
using namespace std;
ifstream F("cmlsc.in");
ofstream G("cmlsc.out");
short a[1024],b[1024],n,m,i,j,k,s[1025][1025],v[1025];
int main()
{
    for(F>>n>>m;i<n;F>>a[i++]);
    for(i=0;i<m;F>>b[i++]);
    for(i=1;i<=n;++i)
        for(j=1;j<=m;s[i][j]=max(s[i-1][j-1]+(a[i-1]==b[j-1]),max(s[i-1][j],s[i][j-1])),++j);
    for(;n||m;a[n-1]==b[m-1]?v[++k]=a[n-1],--n,--m:s[n][m-1]>s[n-1][m]?--m:--n);
    for(G<<k<<'\n';k;G<<v[k--]<<' ');
	return 0;
}
