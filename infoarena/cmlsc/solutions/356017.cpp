#include<stdio.h>
#include<string.h>

int a[1025],b[1025],i,j,m,n,p[1024][1024],c[1024];

int max( int x, int y)
{ 
    if(x>y) return x;
    return y;
}

void cmlscc()
{ int i,j;
   for(i=1;i<=n;i++) 
       for(j=1;j<=m;j++) 
         { if(a[i]==b[j]) p[i][j]=p[i-1][j-1]+1;
          else p[i][j]=max(p[i-1][j],p[i][j-1]);
         } 
   c[0]=0;       
   for(i=n,j=m;p[i][j];)
         if(a[i]==b[j]) { c[++c[0]]=a[i];
                          --i;
                          --j;
                        } 
         else { if(p[i-1][j]>p[i][j-1]) --i;
                else --j;
              }
}                   

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    
    scanf("%d %d",&n,&m);
    
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    for(i=1;i<=m;i++) scanf("%d",&b[i]);
    
    cmlscc();
    
    printf("%d\n",p[n][m]);
    
    for(i=c[0];i>=1;--i) printf("%d ",c[i]);
    printf("\n");
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}

