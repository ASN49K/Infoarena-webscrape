#include<stdio.h>
void main()
{
	FILE *f, *g;
	int i,n,m,j,a[250],b[256],ok, aux[250],k=0;
	f=fopen("cmlsc.in","r");
	g=fopen("cmlsc.out","w");
	fscanf(f,"%d%d",&m,&n);
	for(i=0;i<m;i++)
		fscanf(f,"%d",&a[i]);
	for(j=0;j<n;j++)
		fscanf(f,"%d",&b[j]);
	ok=0;
	for(i=0;i<m;i++)
		for(j=ok;j<n;j++)
			if(a[i]==b[j])
			{
				ok=j;
				aux[k]=a[i];
				k++;
				break;
			}
	fprintf(g,"%d\n",k--);
	for(i=0;i<=k;i++)
		fprintf(g,"%d ",aux[i]);
	fclose(f);
	fclose(g);

}
