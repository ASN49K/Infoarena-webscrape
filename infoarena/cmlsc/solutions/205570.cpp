#include<stdio.h>
int a[1025][1025],b[1025],c[1025],i,j,n,m,d[1025];
int max(int g,int f)
{ if(f>g) return f;
 return g;}
int main()
{ freopen("cmlsc.in","r",stdin);
  freopen("cmlsc.out","w",stdout);
scanf("%d%d",&n,&m);
for(i=1;i<=n;i++)
 scanf("%d",&b[i]);
 for(i=1;i<=m;i++)
   scanf("%d",&c[i]);
for(i=1;i<=n;i++)
 for(j=1;j<=m;j++)
  if(b[i]==c[j])
   a[i][j]=a[i-1][j-1]+1;
  else a[i][j]=max(a[i][j-1],a[i-1][j]);
 printf("%d\n",a[n][m]);
 int nr=a[n][m];
for(i=n;i>=1;i--)
 for(j=m;j>=1;j--)
   if(a[i][j]==a[i-1][j]+1&&a[i][j]==a[i][j-1]+1)
       d[a[i][j]]=b[i];
 for(i=1;i<=nr;i++)
  printf("%d ",d[i]);
return 0;}
