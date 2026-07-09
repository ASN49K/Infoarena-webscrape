#include<cstdio>
#define LUNG 1025
#define MAX(a, b) ((a)>(b)? (a):(b))
int a[LUNG][LUNG],x[LUNG],y[LUNG],s[LUNG],n,m,i,j,nr;
int main()
{
	FILE *f = fopen("cmlsc.in","r");
	FILE *g = fopen("cmlsc.out","w");
	fscanf(f,"%d %d",&n,&m);
	for (i=1;i<=n;i++)
		fscanf(f,"%d",&x[i]);
	for (i=1;i<=m;i++)
		fscanf(f,"%d",&y[i]);
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (x[i]==y[j])
				a[i][j]=a[i-1][j-1]+1;
			else
				a[i][j]=MAX(a[i-1][j], a[i][j-1]);
	i=n;j=m;
	nr=a[n][m];
	while (nr>0)
		if (x[i]==y[j])
		{
			s[nr]=x[i];
			nr--;
			i--;
			j--;
		}
		else
			if(a[i-1][j]>a[i][j-1])
				i--;
			else
				j--;
	fprintf(g,"%d\n",a[n][m]);
	for (i=1;i<=a[n][m];i++)
		fprintf(g,"%d ",s[i]);
	fclose(f);
	fclose(g);
	return 0;
}
