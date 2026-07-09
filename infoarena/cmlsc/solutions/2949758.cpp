#include<fstream>
using namespace std;
ifstream F("1.in");
ofstream G("1.out");
int n,m,a[1025],b[1025],c[1025][1025],d[1025],i,j;
int main()
{
	for(F>>n>>m;i<n;F>>a[i++]);
    for(i=0;i<m;F>>b[i++]);
    for(i=1;i<=n;++i)
        for(j=1;j<=m;c[i][j]=a[i-1]==b[j-1]?c[i-1][j-1]+1:max(c[i-1][j],c[i][j-1]),++j);
    for(;n;a[n-1]==b[m-1]?d[++d[0]]=a[--n],--m:c[n-1][m]<c[n][m-1]?--m:--n);
    for(i=d[0],G<<i<<'\n';i;G<<d[i--]<<' ');
    return 0;
}
