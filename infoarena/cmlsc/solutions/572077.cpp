#include<stdio.h>
#include<malloc.h>

int main()
{
	FILE *f,*g;
	int nr1,nr2,nrmax,nrmin,i,j;
	char a;
	char *v1,*v2;
	int *v3;
	f=fopen("cmlsc.in","r");
	g=fopen("cmlsc.out","w");
	fscanf(f,"%d%d",&nr1,&nr2);
	if(nr1>nr2) 
	{
		nrmax =nr1;
		nrmin =nr2;
		v1=(char*)malloc(nrmax*sizeof(char));
		v2=(char*)malloc(nrmin*sizeof(char));
		for(i=0;i<nrmax;i++)
		{
			fscanf(f,"%c",&a);
			v1[i]=a;	
		}
		for(i=0;i<nrmin;i++)
		{
			fscanf(f,"%c",&a);
			v2[i]=a;	
		}
	}
	else 
	{
		nrmax =nr2;
		nrmin =nr1;
		v1=(char*)malloc(nrmax*sizeof(char));
		v2=(char*)malloc(nrmin*sizeof(char));
		for(i=0;i<nrmin;i++)
		{
			fscanf(f,"%c",&a);
			v1[i]=a;	
		}
		for(i=0;i<nrmax;i++)
		{
			fscanf(f,"%c",&a);
			v2[i]=a;	
		}
	}
	v3=(int*)malloc(nrmax*sizeof(int));
	for(i=0;i<nrmax;i++)
	{
		v3[i]=1;
		for(j=0;i<nrmin;j++)
			if(v1[i]==v2[j]) v3[i]++;
	}
	for(i=0;i<nrmax;i++)
		if(v3[i]>1) fprintf(g,"%d ",v1[i]);

	fclose(g);

	return 0;
}
