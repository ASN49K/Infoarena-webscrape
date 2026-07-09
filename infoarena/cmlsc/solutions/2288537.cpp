#include<cstdio>
using namespace std;
#define N 1025
unsigned char v[N],s[N][N],x[N],y[N];
short int n,m,i,j;
int main() {
    freopen("cmlsc.in","r",stdin),freopen("cmlsc.out","w",stdout),scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",x+i);
    for(i=1;i<=m;i++)
        scanf("%d",y+i);
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        s[i][j]=(x[i]==y[j]?1+s[i-1][j-1]:(std::max(s[i][j-1],s[i-1][j])));
    while(n)
        if(x[n]==y[m])
            v[++v[0]]=x[n--],m--;
        else
            s[n-1][m]<s[n][m-1]?m--:n--;
    printf("%d\n",v[0]);
    for(i=v[0];i;i--)
        printf("%d ",v[i]);
}
