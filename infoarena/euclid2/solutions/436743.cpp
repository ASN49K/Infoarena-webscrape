#include <cstdio>
using namespace std;
int main()
{
	int a,b,aux,i,n;
	FILE *f=fopen("euclid2.in","r");
	FILE *g=fopen("euclid2.out","w");
	fscanf(f,"%d",&n);
	for (i=1;i<=n;i++)
	{
	fscanf(f,"%d %d",&a,&b);
	if (a<b) {aux=a;a=b;b=aux;}
	while (b!=0)
	{
		aux=a%b;
		a=b;
		b=aux;
	}
	fprintf(g,"%d\n",a);
	}
	fclose(f);
	fclose(g);
	return 0;
}