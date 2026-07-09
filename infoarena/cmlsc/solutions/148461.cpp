#include <stdio.h>
int n,m,a[1005],b[1005],d[1005][1005],sir[1005],nr;
int i,j;
int main()
{

	FILE *in,*out;

	in=fopen("cmlsc.in","r");
	out=fopen("cmlsc.out","w");
	fscanf(in,"%d%d\n",&m,&n);	
	for(i=1;i<=m;i++)
		fscanf(in,"%d",&a[i]);
	for(i=1;i<=n;i++)
	fscanf(in,"%d",&b[i]);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[j])
				d[i][j]=1+d[i-1][j-1];
			else
				if (d[i-1][j]>d[i][j-1])
					d[i][j]=d[i-1][j];
				else
					d[i][j]=d[i][j-1];
	for(i=m,j=n;i;)
	if(a[i]==b[j])
	sir[++nr]=a[i],i--,j--;
	else
		if(d[i-1][j]<d[i][j-1])
			j--;
	else
		i--;
	fprintf(out,"%d\n",nr);
	for(i=nr;i>=1;i--)
	fprintf(out,"%d ",sir[i]);
	fclose(in);
	fclose(out);
	return 0;
}
