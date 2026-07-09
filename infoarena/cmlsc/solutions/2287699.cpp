#include<fstream>
#define N 1025
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int v[N],s[N][N],i,j,n,m,x[N],y[N];
int main() {
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>x[i];
    for(i=1;i<=m;i++)
        f>>y[i];
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        s[i][j]=(x[i]==y[j]?1+s[i-1][j-1]:max(s[i-1][j],s[i][j-1]));
    while(n)
        if(x[n]==y[m])
            v[++v[0]]=x[n],n--,m--;
        else
            s[n-1][m]<s[n][m-1]?m--:n--;
    g<<v[0]<<'\n';
    for(i=v[0];i;i--)
        g<<v[i]<<" ";
}
