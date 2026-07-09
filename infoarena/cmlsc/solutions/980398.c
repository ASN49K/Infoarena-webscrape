#include<stdlib.h>
#include<stdio.h>

int n,m;
int sol[1024];
int a[1024],b[1024];
int x,indice,p;

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

int verific(int nr,int x)
{
	int i;
	int ok=0;
	for(i=x;i<m;i++)
		if(nr==b[i])
		{
			ok=1;
			x=i+1;
			return;
		}
	if(!ok)
		return -1;
	else
		return x;


		
}


void back(int k,int len)
{
	if(k==n)
		afis(len);
	else
	{
		p=verific(a[k],indice);
		
		if(p>=0)
		{
			indice=p;
			sol[len]=a[k];
			back(k+1,len+1);
		}
		
		else
			back(k+1,len);
	}

}

int main()
{
	int i;
	citire();
	back(0,0);
	return 0;
}