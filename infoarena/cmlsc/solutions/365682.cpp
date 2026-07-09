#include<stdio.h>
FILE *f=fopen("cmlsc.in","r");
FILE *g=fopen("cmlsc.out","w");

#define M 1025
int n,m,a[M][M],v[M],w[M];

void cit()
{
	int i;
	fscanf(f,"%d%d",&n,&m);
	for(i=1;i<=n;i++)
		fscanf(f,"%d",&v[i]);
	
	for(i=1;i<=m;i++)
		fscanf(f,"%d",&w[i]);
	
	fclose(f);
}

void det()
{
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(v[i]==w[j]) a[i][j]=a[i-1][j-1]+1;
		    else if(a[i-1][j]>a[i][j-1]) a[i][j]=a[i-1][j];
			     else a[i][j]=a[i][j-1];
			
	fprintf(g,"%d\n",a[n][m]);
}

void afis()
{
	int i,j,k=0,b[M];
	i=n;
	j=m;
	
	while(i && j)
	{
		if(v[i]==w[j]) b[++k]=v[i],i--,j--;
		else if(a[i-1][j]>a[i][j-1]) i--;
		     else j--;
	}
	
	for(i=k;i>=1;i--)
		fprintf(g,"%d ",b[i]);
	fclose(g);
}

int main()
{
	cit();
	det();
	afis();
	return 0;
}

