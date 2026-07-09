#include<cstdio>
using namespace std;
FILE *f=fopen("euclid2.in","r");
FILE *g=fopen("euclid2.out","w");
int n, a, b, i, d;
int main()
{
	fscanf(f,"%d",&n);
	for(i=1;i<=n;++i)
	{
		fscanf(f,"%d %d",&a,&b);
		while(a-b)
		{
			if(a>b)a-=b;
			else b-=a;
		}
		fprintf(g,"%d\n",a);
	}
	fclose(f);
	fclose(g);
	return 0;
}
