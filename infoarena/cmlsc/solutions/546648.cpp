#include <cstdio>
FILE *f=fopen("f.in","r");
FILE *g=fopen("f.out","w");
int v1[100],v2[100],v[100],a[100][100],i,j,m,n,k;
int main()
{
	fscanf(f,"%d%d",&n,&m);
	
	for(i=1;i<=n;i++)
		fscanf(f,"%d",&v1[i]);
	
	for(i=1;i<=m;i++)
		fscanf(f,"%d",&v2[i]);
	
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(v1[i]==v2[j])
				a[i][j]=a[i-1][j-1]+1;
			else
			{
				if(a[i-1][j]>a[i][j-1])
					a[i][j]=a[i-1][j];
				else
					a[i][j]=a[i][j-1];
				
			}
			
	k=a[n][m];
	i=n;
	j=m;
	
	while(a[i][j])
		if(a[i][j]==a[i-1][j])
			i--;
		else
			if(a[i][j]==a[i][j-1])
				j--;
			else
			{
				v[k]=v1[i];
				i--;
				j--;
				k--;
			}
			
	fprintf(g,"%d\n",a[n][m]);
	
	for(i=1;i<=a[n][m];i++)
		fprintf(g,"%d ",v[i]);
	fclose(f);
	
	fclose(g);
	return 0;
}
