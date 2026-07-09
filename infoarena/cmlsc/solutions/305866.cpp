#include <stdio.h>
#define N 1026
#define max(a,b) ((a>b)?(a):(b))
FILE *f=fopen("cmlsc.in","r");
FILE *g=fopen("cmlsc.out","w");
int m[N][N],a[N],b[N],n,m2,i,j,s[N],mx;
int main()
 {
 fscanf(f,"%d %d",&n,&m2);
 for(i=1;i<=n;i++)
  fscanf(f,"%d",&a[i]);
 for(i=1;i<=m2;i++)
  fscanf(f,"%d",&b[i]);
 for(i=1;i<=n;i++)
  for(j=1;j<=m2;j++)
   if(a[i]==b[j])
    m[i][j]=m[i-1][j-1]+1;
   else
    m[i][j]=max(m[i-1][j],m[i][j-1]);
  fprintf(g,"%d\n",m[n][m2]);
  mx=m[n][m2];
 for(i=n,j=m2;i>=1&&mx>0;(j==1)?(j=m2,i--):(j--))
  if(a[i]==b[j]&&mx==m[i][j]&&m[i][j]==m[i-1][j-1]+1)
   {
   s[mx]=a[i];
   mx--;
   i--;
   j--;
   }
 for(i=1;i<=m[n][m2];i++)
  fprintf(g,"%d ",s[i]);
 return 0;         
 }
