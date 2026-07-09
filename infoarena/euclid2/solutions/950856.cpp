#include<cstdio>
using namespace std;
FILE *f=fopen("euclid2.in","r");
FILE *g=fopen("euclid2.out","w");
int n, a, b, i, d, r;
int main()
{
	fscanf(f,"%d",&n);
	for(i=1;i<=n;++i)
	{
		fscanf(f,"%d %d",&a,&b);
		do
		{
			r=a%b;
			a=b;
			b=r;
		}while(r>0);
		fprintf(g,"%d\n",a);
	}
	fclose(f);
	fclose(g);
	return 0;
}
