#include<fstream>
using namespace std;
#define N 1025
ifstream g("cmlsc.in");
ofstream p("cmlsc.out");
unsigned char v[N],s[N][N],x[N],y[N];
short int n,m,i,j;
int main() {
    g>>n>>m;
    for(i=1;i<=n;i++)
        g>>x[i];
    for(i=1;i<=m;i++)
        g>>y[i];
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        s[i][j]=(x[i]==y[j]?1+s[i-1][j-1]:max(s[i][j-1],s[i-1][j]));
    while(n)
        if(x[n]==y[m])
            v[++v[0]]=x[n--],m--;
        else
            s[n-1][m]<s[n][m-1]?m--:n--;
    p<<v[0]<<"\n";
    for(i=v[0];i;i--)
        p<<v[i]<<" ";
    return 0;
}
