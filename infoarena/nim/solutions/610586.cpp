#include <stdio.h>
using namespace std;
int n,m,i,j,rez,a;
FILE *f,*g;
int main()
{
	f=fopen("nim.in","r");
	g=fopen("nim.out","w");
	fscanf(f,"%d",&n);
	for (i=1;i<=n;++i)
	{
		fscanf(f,"%d",&m);
		rez=0;
		for (j=1;j<=m;++j)
		{
			fscanf(f,"%d",&a);
			rez=rez^a;
		}
		if (rez)
			fprintf(g,"DA\n");
		else
			fprintf(g,"NU\n");
	}
	fclose(f);
	fclose(g);
	return 0;
}
