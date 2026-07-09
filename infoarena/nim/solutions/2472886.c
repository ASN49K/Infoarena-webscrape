#include<stdio.h>

int main()
{
FILE *f,*g;
int n,t,xor;
f=fopen("nim.in","r");
g=fopen("nim.out","w");
fscanf(f,"%d",&t);
while(t--)
{
fscanf(f,"%d",&n);
xor=0;
int i;
for(i=1;i<=n;i++)
{int nr;
	fscanf(f,"%d",&nr);
	xor=xor^nr;
}
if(xor)
	fprintf(g,"DA\n");
	else
	fprintf(g,"NU\n");
}
	return 0;
}
