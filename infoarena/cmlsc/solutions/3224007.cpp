#include<fstream>
using namespace std;
ifstream F("cmlsc.in");
ofstream G("cmlsc.out");
short s[1025][1025],n,m,i,j,a[1025],b[1025],c[1025];
int main()
{
    for(F>>n>>m,i=1;i<=n;F>>a[i++]);
    for(i=1;i<=m;F>>b[i++]);
    for(i=1;i<=n;++i)
        for(j=1;j<=m;s[i][j]=max<short>(s[i-1][j-1]+(a[i]==b[j]),max(s[i-1][j],s[i][j-1])),++j);
    for(;n;a[n]==b[m]?c[++c[0]]=a[n--],--m:s[n-1][m]<s[n][m-1]?--m:--n);
    for(i=c[0],G<<i<<'\n';i;G<<c[i--]<<' ');
    return 0;
}
