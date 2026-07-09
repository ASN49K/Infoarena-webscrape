#include <stdio.h>
int m,n,a[1025],b[1025],c[1025][1025],s[1025],nr;
int main()
{
 freopen("cmlsc.in","r",stdin);
 freopen("cmlsc.out","w",stdout);
 scanf("%d %d\n",&m,&n);
 int i,j;
 for (i=1;i<=m;i++)
  scanf("%d",&a[i]);
 for (i=1;i<=n;i++)
  scanf("%d",&b[i]);
 for(i=1;i<=m;i++)
  for (j=1;j<=n;j++)
   if (a[i]==b[j])
    c[i][j]=c[i-1][j-1]+1;
   else
    c[i][j]=c[i-1][j]>c[i][j-1] ? c[i-1][j] : c[i][j-1];
 i=m;
 j=n;
 while (i&&j)
 {
  if (a[i]==b[j])
  {
   s[nr]=a[i];
   nr++;
   i--;
   j--;
  }
  else
   if (c[i-1][j]>c[i][j-1])
    i--;
   else
    j--;
 }
 printf("%d\n",nr);
 for (i=nr-1;i>=0;i--)
  printf("%d ",s[i]);
 return 0;
}