#include"stdio.h"
int main()
{int a,b,n,i;
FILE *F,*G;
F=fopen("euclid2.in","r");
G=fopen("euclid2.out","w");
fscanf(F,"%d",&n);
for (i=1;i<=n;i++)
{
fscanf(F,"%d",&a);
fscanf(F,"%d",&b);
int r;
r=a%b;
while(r!=0)
	{
	a=b;
	b=r;
	r=a%b;
	}
fprintf(G,"%d\n",b);
}
fclose(F);
fclose(G);
return 0;
}