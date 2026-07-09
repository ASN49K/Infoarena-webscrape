#include <stdio.h>
#define nmax 1025;
int a[nmax],b[nmax],d[nmax][nmax], sol[nmax],k;
int main()
{int i,j,n,m;

freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);

scanf("%d %d",&m,&n);
for (i=1; i<=m; i++)
scanf("%d",&a[i]);

for (i=1; i<=n; i++)
scanf("%d",&b[i]);


for (i=1; i<=m; i++)
  for (j=1;j<=n;j++)
    if (a[i]==b[j])
     d[i][j]=d[i-1][j-1]+1;
     else
      if (d[i][j-1]>d[i-1][j])
      d[i][j]=d[i][j-1];
      else d[i][j]=d[i-1][j];

k=d[m][n];
for (i=m,j=n;i;)
 if (a[i]==b[j])
  {sol[--k]=a[i]; i--;j--;}
 else
  (d[i][j]==d[i-1][j])?i--:j--;

printf("%d\n",d[m][n]);
for (i=0;i<d[m][n];i++)
printf("%d ",sol[i]);

return (0);
}


