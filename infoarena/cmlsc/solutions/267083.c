#include <stdio.h>
#include <string.h>
int c[1030][1030],a[1030],b[1030],d[1030],n,m,j,i,k;
int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(i=1; i<=n; i++) scanf("%d",&a[i]);
    for(j=1; j<=m; j++) scanf("%d",&b[j]);
    c[0][0]=0;
    for(i=1; i<=n; i++)
     for(j=1; j<=m; j++)
      if(a[i]==b[j])
       c[i][j]=c[i-1][j-1]+1;
      else
       c[i][j]=max(c[i-1][j],c[i][j-1]);
     printf("%d\n",c[n][m]);
    for(i=n,j=m; i;)
    {
        if(a[i]==b[j])
        {
            d[++k]=a[i];
            --i;
            --j;
        }
        else
         if(c[i-1][j]<c[i][j-1]) --j;
         else --i;
    }
    for(i=k; i; --i) printf("%d ",d[i]);
     return 0;
}
