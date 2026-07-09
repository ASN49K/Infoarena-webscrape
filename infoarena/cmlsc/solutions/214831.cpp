#include <stdio.h>
#define maxim(a,b)(a>b?a:b);
int a[1025],b[1025],n,m,d[1026][1026],i,j,c;
int main(void)
{
  freopen("cmlsc.in","r",stdin);
  freopen("cmlsc.out","w",stdout);
  scanf("%d %d",&n,&m);
  for(i=n;i;--i)
    scanf("%d",&a[i]);
  for(i=m;i;--i)
    scanf("%d",&b[i]);
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
      if(a[i]==b[j])
	d[i][j]=d[i-1][j-1]+1;
      else
	d[i][j]=maxim(d[i][j-1],d[i-1][j]);
  c=d[n][m];
  printf("%d\n",c);
  for(i=n,j=m;j;)
    if(a[i]==b[j])
      {
	printf("%d ",b[j]);
	--i;
	--j;
      }
    else
      if(d[i-1][j]>d[i][j-1])
	--i;
      else
	--j;
  return 0;
}