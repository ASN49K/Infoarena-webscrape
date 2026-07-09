#include <stdio.h> 
#define MAX(a,b) ((a > b) ? a : b)

int m,n,a[1024],b[1024],i,j,t[1024][1024];
int sc[1024],lsc;

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    
    scanf("%d %d\n",&m,&n);
    for (i=1;i<=m;++i)
        scanf("%d",&a[i]);
    for (i=1;i<=n;++i)
        scanf("%d",&b[i]);
    
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
            if (a[i] == b[j])
               t[i][j]=t[i-1][j-1]+1;
            else 
               t[i][j]=MAX(t[i-1][j],t[i][j-1]);
    
    for (i=m,j=n;(i>0)&&(j>0);)
        if (a[i]==b[j])
        {
           sc[++lsc]=a[i];
           --i;--j;
        }
        else if(t[i-1][j] < t[i][j-1])
             --j;
        else --i;
        
    printf("%d\n",t[m][n]);
    for (i=lsc;i>0;--i)
        printf("%d ",sc[i]);
        
    return 0;
}
