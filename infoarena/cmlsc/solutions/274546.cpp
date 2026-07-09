#include <stdio.h>

int n,m,a[1025],b[1025],i,j,sir[1025],l,d[1025][1025];

inline int max(int a,int b) { return a>b?a:b; }

int main()
{
  freopen("cmlsc.in","r",stdin);
  freopen("cmlsc.out","w",stdout);

  scanf("%d %d", &n,&m);
  for (i=1;i<=n;++i)
       scanf("%d", &a[i]);
  for (j=1;j<=m;++j)
       scanf("%d", &b[j]);

  for (i=1;i<=n;++i)
       for (j=1;j<=m;++j)
       if (a[i]==b[j])
	   d[i][j]=d[i-1][j-1]+1;
	   else
	   d[i][j]=max(d[i-1][j],d[i][j-1]);

  l=0;
  for (i=n,j=m;i,j;)
       if (a[i]==b[j])
	   sir[++l]=a[i],i--,j--;
	   else
	   if (d[i-1][j]>d[i][j-1])
	       i--;
	       else
	       j--;
  printf("%d\n", l);
  for (i=l;i>=1;--i)
       printf("%d ", sir[i]);
  return 0;
}