#include<stdio.h>

using namespace std;

int main()
{
	FILE *f,*g;
	f=fopen("cmlsc.in","r");
	g=fopen("cmlsc.out","w");
	int n,m,i,j,v[1024],w[1024],k=0;
	fscanf(f,"%d %d",&n,&m);
	for (i=1;i<=n;i++)
			fscanf(f,"%d", &v[i]);
	for (j=1;j<=m;j++)
		{
			int x;
			fscanf(f,"%d",&x);
			for (i=1;i<=n;i++)
				if (x==v[i])
				{
					k++;
					w[k]=x;
				}
	}
	fclose(f);
	fprintf(g,"%d\n",k);
	for (i=1;i<=k;i++)
		fprintf(g,"%d ",w[i]);
	fclose(g);
	return 0;
}
