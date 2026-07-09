#include<stdio.h>
#include<malloc.h>

int main()
{
	FILE *f,*g;
	int nr1,nr2,nrmax,nrmin,i,j,k=0;
	int a;
	int *v1,*v2;
	int *v3;
	f=fopen("cmlsc.in","r");
	g=fopen("cmlsc.out","w");
	fscanf(f,"%d%d",&nr1,&nr2);
	if(nr1>nr2) 
	{
		nrmax =nr1;
		nrmin =nr2;
		v1=(int*)malloc(nrmax*sizeof(int));
		v2=(int*)malloc(nrmin*sizeof(int));
		for(i=0;i<nrmax;i++)
		{
			fscanf(f,"%d",&a);
			v1[i]=a;	
		}
		for(i=0;i<nrmin;i++)
		{
			fscanf(f,"%d",&a);
			v2[i]=a;	
		}
	}
	else 
	{
		nrmax =nr2;
		nrmin =nr1;
		v1=(int*)malloc(nrmax*sizeof(int));
		v2=(int*)malloc(nrmin*sizeof(int));
		for(i=0;i<nrmin;i++)
		{
			fscanf(f,"%d",&a);
			v2[i]=a;	
		}
		for(i=0;i<nrmax;i++)
		{
			fscanf(f,"%d",&a);
			v1[i]=a;	
		}
	}
	v3=(int*)malloc(nrmax*sizeof(int));
	for(i=0;i<nrmax;i++)
		v3[i]=1;

	for(j=0;j<nrmin;j++)
		for(i=0;i<nrmax;i++)
			if(v1[i]==v2[j]) 
			{
				v3[i]++;
				k++;
			}
	fprintf(g,"%d\n",k);
	for(i=0;i<nrmax;i++)
		if(v3[i]>1) fprintf(g,"%d ",v1[i]);

	fclose(g);

	return 0;
}
