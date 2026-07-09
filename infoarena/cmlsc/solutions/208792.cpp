#include<stdio.h>
#define dim 1024

int i,j,m,n;
int a[dim],b[dim];

int main()
{

FILE*f=fopen("cmlsc.in","r"),*g=fopen("cmlsc.out","w");

fscanf(f,"%i %i",&m,&n);
 for(i=1;i<=m;i++)
  fscanf(f,"%i",&a[i]);
 for(i=1;i<=n;i++)
  fscanf(f,"%i",&b[i]);
int s=1,k=0;

for(i=1;i<=m;i++)
 for(j=s;j<=n;j++)
  if(a[i]==b[j])
   {s=j+1;
   k++;
   b[k]=a[i];
   }
	fprintf(g,"%i\n",k);
	for(i=1;i<=k;i++)
	  if(i==k)
	 fprintf(g,"%i",b[i]);
	  else
	 fprintf(g,"%i ",b[i]);

 return 0;}