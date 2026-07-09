#include<stdio.h>
FILE *f=fopen("euclid2.in","r");
FILE *g=fopen("euclid2.out","w");
long a,b,n;
int i,r;
int main()
{
fscanf(f,"%d",&n);
for(i=1;i<=n;i++){ fscanf(f,"%d %d",&a,&b);
		   while(b!=0){ r=a%b; a=b;b=r;}
		   fprintf(g,"%d\n",a);
		 }
fclose(f);
fclose(g);
return 0;
}