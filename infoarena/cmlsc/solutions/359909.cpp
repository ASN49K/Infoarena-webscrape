#include<cstdio>
using namespace std;

int a[1024],b[1024],c[1024][1024],n,m,i,j,s[1024],t;

int max(int x, int y)
{
	if (x>y)
		return x;
	else return y;
}
int main()
{
	FILE *f=fopen("cmlsc.in","r");
	FILE *g=fopen("cmlsc.out","w");
	fscanf(f,"%d %d",&n,&m);
	for (i=1;i<=n;i++)
		fscanf(f,"%d ",&a[i]);
	for (j=1;j<=m;j++)
		fscanf(f,"%d ",&b[j]);
	for (i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if (a[i]==b[j])
				c[i][j]=c[i-1][j-1]+1;
			else
				c[i][j]=max(c[i-1][j],c[i][j-1]);
	i=n;
	j=m;
	t=1;
	while (i&&j)
	{
		if (a[i]==b[j])
		{
		s[t]=a[i];
		i--; j--;
		t++;
		}
		else
		{
		if (c[i-1][j]>c[i][j-1])
			i--;
		else
			j--;
		}
	}
	fprintf (g,"%d ",c[n][m]);
	fprintf(g,"\n");
	for (i=c[n][m];i>0;i--)
		fprintf(g,"%d ",s[i]);
	fclose(f);
	fclose(g);
	return 0;
}
