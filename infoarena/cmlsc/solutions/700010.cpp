#include<stdio.h>
FILE *fin,*fout;
int n,m;
int a[1024],b[1024];
int c[1024],d[1024][1024];

main()
{
int i,j;
fin = fopen("cmlsc.in","r");
fout = fopen("cmlsc.out","w");
fscanf(fin,"%d%d",&n,&m);
for(i=1;i<=n;i++)
	fscanf(fin,"%d",&a[i]);
for(i=1;i<=m;i++)
	fscanf(fin,"%d",&b[i]);
for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
		if(a[i]==b[j])
		{
			d[i][j]=1+d[i-1][j-1];
			c[d[i][j]]=a[i];
		}
		else
		{
			if(d[i-1][j]>d[i][j-1])
				d[i][j]=d[i-1][j];
			else
				d[i][j]=d[i][j-1];
		}
fprintf(fout,"%d\n",d[n][m]);
for(i=1;i<=d[n][m];i++)
	fprintf(fout,"%d ",c[i]);
fclose(fin);
fclose(fout);
}
