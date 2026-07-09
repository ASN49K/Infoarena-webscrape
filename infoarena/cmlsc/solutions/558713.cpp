#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
FILE*f=fopen("cmlsc.in","r");
FILE*g=fopen("cmlsc.out","w");
short int d[1025],p,a[1025],b[1025],n,m;
short int lcs[1025][1025];
int main()
  {
  int i,j;
  fscanf(f,"%d %d",&n,&m);
  for(i=1;i<=n;++i) fscanf(f,"%d",&a[i]);
  for(i=1;i<=m;++i) fscanf(f,"%d",&b[i]);
  for(i=1;i<=n;++i)
   for(j=1;j<=m;++j)
     if(a[i]==b[j]) lcs[i][j]=1+lcs[i-1][j-1];
     else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
  for(i=n,j=m;i,j;)
   {
   if(a[i]==b[j]) d[++p]=a[i],i--,j--;
   else if(lcs[i][j-1]>lcs[i-1][j]) --j;
   else --i;
   }
  fprintf(g,"%d\n",lcs[n][m]);
  for(i=p;i>=1;--i) fprintf(g,"%d ",d[i]);
  return 0;
  }