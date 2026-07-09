#include<stdio.h>
using namespace std;

int n,x,y,i;

int euclid(int a,int b)
{
	int r=1;
	while(r!=0)
	{r=a%b;
	a=b;
	b=r;}
	return a;
}

int main()
{
	FILE *f=fopen("euclid2.in","r"), *g=fopen("euclid2.out","w");

fscanf(f,"%d",&n);
for(i=1;i<=n;i++)
{
	fscanf(f,"%d %d",&x,&y);
	fprintf(g,"%d\n",euclid(x,y));
}


fclose(f);
fclose(g);
return 0;
}
