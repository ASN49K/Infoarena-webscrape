#include<stdio.h>
int m,n,a[1025],b[1025],nr;

int main()
{
	FILE *f;
	FILE *g;
	f=fopen("cmlsc.in","rt");
	g=fopen("cmlsc.out","wt");
	fscanf(f,"%d %d", &m, &n);
	for(int i=1;i<=m;i++)
		fscanf(f,"%d", &a[i]);
	for(int i=1;i<=n;i++)
		fscanf(f,"%d", &b[i]);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(a[i]==b[j])
				nr++;
	fprintf(g,"%d\n", nr);
    for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(a[i]==b[j])
				fprintf(g,"%d ", a[i]);
	fclose(f);
	fclose(g);
	return 0;
}