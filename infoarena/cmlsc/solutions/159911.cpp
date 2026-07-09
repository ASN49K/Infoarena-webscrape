#include <stdio.h>
#define max(a, b) ((a > b) ? a : b)
FILE *f=fopen("cmlsc.in","r"),*g=fopen("cmlsc.out","w");
int m,n,a[1025],b[1025],d[1025][1025],sir[1024],bs;
int main()
{
 int i,j;
 fscanf(f,"%d %d",&m,&n);
 for(i=1;i<=m;i++)
   fscanf(f,"%d",&a[i]);
 for(i=1;i<=n;i++)
   scanf("%d",&b[i]);
 for(i=1;i<=m;i++)
   for(j=1;j<=n;j++)
     if(a[i]==b[j]) d[i][j]=1+d[i-1][j-1];
     else d[i][j]=max(d[i-1][j],d[i][j-1]);
 for(i=m,j=n;i;)
   if(a[i]==b[j]) sir[++bs]=a[i],i--,j--;
   else if(d[i-1][j]<d[i][j-1]) j--;
	else i--;
 printf("%d\n",bs);
 for(i=bs;i;i--)
   printf("%d ",sir[i]);
 return 0;
}
