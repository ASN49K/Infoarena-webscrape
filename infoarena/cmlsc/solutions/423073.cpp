#include <stdio.h>
FILE *f=fopen("cmlsc.in","r"),*g=fopen("cmlsc.out","w");
int d[1025][1025],i,j,sir[1025],n,m,a[1025],b[1025],bst;
int main(void)
{
	fscanf(f,"%d%d",&n,&m);
	for (i=1;i<=n;i++)
		fscanf(f,"%d",&a[i]);
	for (i=1;i<=m;i++)
		fscanf(f,"%d",&b[i]);
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		{
			if (a[i]==b[j])
				d[i][j]=1+d[i-1][j-1];
			else
			{
				if (d[i-1][j]>d[i][j-1])
					d[i][j]=d[i-1][j];
				else d[i][j]=d[i][j-1];
			}
		}
	for (i=n,j=m;i;)
		if (a[i]==b[j])
		{
			sir[++bst]=a[i];
			i--;
			j--;
		}
		else
		{
			if (d[i-1][j]>d[i][j-1])
				i--;
			else j--;
		}
	fprintf(g,"%d\n",bst);
	for (i=bst;i>=1;i--)
		fprintf(g,"%d ",sir[i]);
	fclose(g);
	return 0;
}