#include <stdio.h>
long sir1[1025],sir2[1025],a[1025][1025],i,j,n,m,k,p[1025],v[1025],l;        
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%ld %ld",&n,&m);
    
    for(i=1;i<=n;i++)
    scanf("%ld",&sir1[i]);
    
    for(i=1;i<=m;i++)
    scanf("%ld",&sir2[i]);

    for(i=n;i>=1;i--)
    for(j=m;j>=1;j--)
    {
     if(sir1[i]==sir2[j])
     {
     k++;
     a[i][j]=a[i+1][j+1]+1;
     if(v[k-1]!=a[i][j]){v[k]=a[i][j];p[k]=i;}
     else k--;
     }
     else if(a[i][j+1]>a[i+1][j])a[i][j]=a[i][j+1];
     else a[i][j]=a[i+1][j];
    }
    l=a[1][1];
    printf("%ld\n",l);
    /*for(i=1;i<=n;i++)
    {
    for(j=1;j<=m;j++)
    printf("%ld",a[i][j]);
    printf("\n");
    }*/
    
    /*for(i=k;i>=1;i--)
    {
    if(v[i]==l)
    {
    l--;
    printf("%ld ",sir1[p[i]]);
    }
    }*/
    for(i=1;i<=k;i++)
    printf("%ld ",sir1[p[i]]);
    return 0;  
}
