#include<stdio.h>
#define N 1025
#define M(a,b) (a<b?b:a)
unsigned char v[N],s[N][N],x[N],y[N];
short n,m,i,j;
int main()
{
    freopen("cmlsc.in","r",stdin),freopen("cmlsc.out","w",stdout),scanf("%hd%hd",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%hd",x+i);
    for(i=1;i<=m;i++)
        scanf("%hd",y+i);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            s[i][j]=(x[i]==y[j]?1+s[i-1][j-1]:M(s[i][j-1],s[i-1][j]));
    while(n)
        if(x[n]==y[m])
            v[++v[0]]=x[n--],m--;
        else
            s[n-1][m]<s[n][m-1]?m--:n--;
    printf("%hd\n",v[0]);
    for(i=v[0];i;i--)
        printf("%hd ",v[i]);
}
