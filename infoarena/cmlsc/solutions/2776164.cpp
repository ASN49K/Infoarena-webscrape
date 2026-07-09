#include<fstream>
#include<algorithm>
using namespace std;
#define N 1025
ifstream F("cmlsc.in");
ofstream G("cmlsc.out");
short n,m,i,j,s[N][N],v[N],x[N],y[N];
int main()
{
    F>>n>>m;
    for(i=1;i<=n;++i)
        F>>x[i];
    for(i=1;i<=m;++i)
        F>>y[i];
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            s[i][j]=(x[i]==y[j]?1+s[i-1][j-1]:max(s[i][j-1],s[i-1][j]));
    while(n)
        if(x[n]==y[m])
            v[++v[0]]=x[n--],--m;
        else
            s[n-1][m]<s[n][m-1]?--m:--n;
    for(G<<v[0]<<"\n",i=v[0];i;--i)
        G<<v[i]<<" ";
    return 0;
}
