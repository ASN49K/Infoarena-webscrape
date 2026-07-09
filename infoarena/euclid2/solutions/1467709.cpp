#include<stdio.h>
#include<string.h>
int euclid(int a,int b)
{
	if(!b) return a;
	else euclid(b,a%b);
}
int main()
{
FILE *f;
FILE *g;
g=fopen("euclid2.out","wt");
f=fopen("euclid2.in","rt");
int t=0,a,b;
fscanf(f,"%d",&t);
printf("%d",t);
for(int i=0;i<t;i++)	
{
	fscanf(f,"%d %d",&a,&b);
//	printf("%d",euclid(a,b));
	fprintf(g,"%d\n",euclid(b,a));
}
	
	
	return 0;
}
