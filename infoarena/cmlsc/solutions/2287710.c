#include<stdio.h>
#define N 1025
unsigned char v[N],s[N][N],x[N],y[N],i,j,n,m;
int main() {
    freopen("cmlsc.in","r",stdin),freopen("cmlsc.out","w",stdout),scanf("%c%c",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%c",x+i);
    for(i=1;i<=m;i++)
        scanf("%c",y+i);
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        s[i][j]=(x[i]==y[j]?1+s[i-1][j-1]:(s[i][j-1]<s[i-1][j]?s[i-1][j]:s[i][j-1]));
    while(n)
        if(x[n]==y[m])
            v[++v[0]]=x[n],n--,m--;
        else
            s[n-1][m]<s[n][m-1]?m--:n--;
    printf("%d\n",v[0]);
    for(i=v[0];i;i--)
        printf("%d ",v[i]);
}
