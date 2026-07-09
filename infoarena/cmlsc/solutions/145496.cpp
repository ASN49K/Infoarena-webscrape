#include<stdio.h>
#define nmax 1025
#define max(a,b) ((a)>(b) ? (a):(b) )
int a[nmax],b[nmax],sol[nmax][nmax],solt[nmax];
int aux;

int main()
{
    
 freopen("cmlsc.in","r",stdin);
 freopen("cmlsc.out","w",stdout);
 
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    
    for(i=1; i<=n; ++i)
    scanf("%d",&a[i]);
    for(i=1; i<=m; ++i)
    scanf("%d",&b[i]);
    
    for(i=1; i<=n; ++i)
             for(j=1; j<=m; ++j)
            {
                      if( a[i] == b[j])
                      sol[i][j]=sol[i-1][j-1]+1;
                      else
                      sol[i][j]=max(sol[i-1][j],sol[i][j-1]);
    
            }
    
    printf("%d\n",sol[n][m]);
    
    for(i=n,j=m; i&&j; )
    {
                 if( a[i]==b[j]){
                 solt[++aux]=a[i]; --i; --j;}
                 else
                 if( sol[i][j-1]>sol[i-1][j])
                 --j;
                 else
                 --i;
                 }
    
    for(i=aux; i>=1; --i)
    printf("%d ",solt[i]);
    printf("\n");
    
    
    
    
    
    
    return 0;
}
