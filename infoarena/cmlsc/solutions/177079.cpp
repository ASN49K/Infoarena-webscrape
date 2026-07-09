#include<stdio.h>

#define maxim(a,b) ((a>b) ? a : b)
#define max 1024

int m,n,a[max],b[max],i,j,d[max][max],sir[max],nr;

void citire()
{
 freopen("cmlsc.in","r",stdin);
 freopen("cmlsc.out","w",stdout);
 scanf("%d %d",&m,&n);
 for(i=1;i<=m;i++)
    scanf("%d", &a[i]);
 for(i=1;i<=n;i++)
   scanf("%d",&b[i]);
 }

int main()
{
 citire();
 for(i=1;i<=m;i++)
   for(j=1;j<=n;j++)
        if(a[i]==b[j])
           d[i][j]=1+d[i-1][j-1];
          else d[i][j]=maxim(d[i-1][j],d[i][j-1]);
  for(i=m;i<=n;i++)
      if(a[i]==b[i])
         sir[++nr]=a[i],--i,--j;
        else if(d[i-1][j]<d[i][j-1]) --j;
                else  --i;
    printf("%d\n",nr);
   for(i=nr;i>=1;i--)
       printf("%d",sir[i]);
return 0;
}

