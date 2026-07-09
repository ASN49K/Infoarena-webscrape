#include<fstream>
using namespace std;
ifstream F("cmlsc.in");
ofstream G("cmlsc.out");
#define N 1025
int n,m,i,j,s[N][N],v[N],x[N],y[N];
int main()
{
    for(F>>n>>m,i=1;i<=n;F>>x[i],++i);
    for(i=1;i<=m;F>>y[i],++i);
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            s[i][j]=x[i]==y[j]?1+s[i-1][j-1]:max(s[i][j-1],s[i-1][j]);
    for(;s[n][m];x[n]==y[m]?v[++v[0]]=x[n],--n,--m:s[n-1][m]<s[n][m-1]?--m:--n);
    for(G<<v[0]<<'\n',i=v[0];i;G<<v[i]<<' ',--i);
    return 0;
}
