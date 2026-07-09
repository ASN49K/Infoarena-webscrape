#include<stdlib.h>
#include<stdio.h>

int n,m;
int sol[1024];
int a[1024],b[1024];

void citire()
{
	FILE *f;
	int i,j;
	f=fopen("cmlsc.in","rt");
	if(f==NULL)
	{
		printf("eroare");
		return;
	}
	fscanf(f,"%d %d",&n,&m);
	for(i=0;i<n;i++)
		fscanf(f,"%d ",&a[i]);
	for(j=0;j<m;j++)
		fscanf(f,"%d ",&b[j]);
}


void afis(int len)
{
	FILE *fout;
	int i;
	fout=fopen("cmlsc.out","wt");
	fprintf(fout,"%d\n",len);
	for(i=0;i<len;i++)
		fprintf(fout,"%d ",sol[i]);
	fclose(fout);
}

int verific(int nr)
{
	int i;
	for(i=0;i<m;i++)
		if(nr==b[i])
			return 1;
	return 0;
}

void back(int k,int len)
{
	if(k==n)
		afis(len);
	else
	{
		if(verific(a[k]))
		{
				sol[len]=a[k];
				back(k+1,len+1);
		}
		else
			back(k+1,len);
	}

}

int main()
{
	citire();
	back(0,0);
	return 0;
}