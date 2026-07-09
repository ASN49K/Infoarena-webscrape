#include<stdio.h>
FILE *f=fopen("cmlsc.in","r");
FILE *g=fopen("cmlsc.out","w");

#define M 1024
int v[M],n,m,x[M],y[M];

void cit()
{
	fscanf(f,"%d%d",&m,&n);
	int i;
	
	for(i=1;i<=m;i++)
		fscanf(f,"%d",&x[i]);
	
	for(i=1;i<=n;i++)
		fscanf(f,"%d",&y[i]);
	
	fclose(f);
}


int main()
{
	cit();
	int k=0,i,j;
	
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
			if(x[i]==y[j]) {v[++k]=x[i];
		                     break;}
	}
	
	fprintf(g,"%d\n",k);
	for(i=1;i<=k;i++)
		fprintf(g,"%d ",v[i]);
	
	fclose(g);
	return 0;
}
	
	