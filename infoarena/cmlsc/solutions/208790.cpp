#include<stdio.h>
#define dim 1024


int main()
{ int i,j,m,n;
  int a[dim],b[dim];

FILE*f=fopen("cmlsc.in","r"),*g=fopen("cmlsc.out","w");

fscanf(f,"%i %i",&m,&n);
 for(i=1;i<=m;i++)
  fscanf(f,"%i",&a[i]);
 for(i=1;i<=n;i++)
  fscanf(f,"%i",&b[i]);
int s=1;

for(i=1;i<=m;i++)
 for(j=s;j<=n;j++)
  if(a[i]==b[j])
   {s++;
   b[s-1]=a[i];
   }
	fprintf(g,"%i\n",s);
	for(i=1;i<s;i++)
	 fprintf(g,"%i ",b[i]);

 return 0;}