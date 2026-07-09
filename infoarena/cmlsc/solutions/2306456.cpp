#include<cstdio>
#define N 1024
#define M(a,b) (a<b?b:a)
int v[N],s[N][N],x[N],y[N],n,m,i,j;
int main()
{
    freopen("cmlsc.in","r",stdin),freopen("cmlsc.out","w",stdout),scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",x+i);
    for(i=0;i<m;i++)
        scanf("%d",y+i);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            s[i][j]=(x[i]==y[j]?1+s[i-1][j-1]:M(s[i][j-1],s[i-1][j]));
    while(n>=0)
        if(x[n-1]==y[m-1])
            v[++v[0]]=x[n-1],m--,n--;
        else
            s[n-2][m-1]<s[n-1][m-2]?m--:n--;
    printf("%d\n",v[0]);
    for(i=v[0];i;i--)
        printf("%d ",v[i]);
}
