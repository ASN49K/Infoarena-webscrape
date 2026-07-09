#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void read(int *n,int **a,int *m,int **b)
{
	FILE *f=fopen("cmlsc.in","r");
	int i;
	fscanf(f,"%d %d",n,m);
	*a=(int*) malloc((*n)*sizeof(int));
	for(i=0;i<(*n);i++)
			fscanf(f,"%i",&(*a)[i]);
	//fscanf(f,"%d",m);
	*b=(int*)malloc((*m)*sizeof(int));
	for(i=0;i<(*m);i++)
			fscanf(f,"%i",&(*b)[i]);
	fclose(f);
	}	
/*void print(int *a,int *b,int n,int m)
{
	FILE *g=fopen("cmlsc.out","w");
	
	int i=0;
	for(i=0;i<n;i++)
		fprintf(g,"%d ",a[i]);
	fprintf(g,"\n");
	for(i=0;i<m;i++)
			fprintf(g,"%d ",b[i]);
	fclose(g);
}*/			
int elcomune(int *a,int*b,int n,int m)
{
		int mat[256][256];
		int i,j;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				mat[i][i]=0;
	/*	mat=(int **)malloc((n)*sizeof(int*));
		for(i=0;i<m;i++)
			mat[i]=(int*)malloc((m)*sizeof(int*));*/
		int el=0;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
					if(i==0 || j==0)
						{if(a[i]==b[j]) mat[i][j]=1; el++;}
					else
						{if(a[i]==b[j]) mat[i][j]=mat[i-1][j-1]+1;
						el++;}
		int v[256];
		int k=0;		el=0;
		for(i=0;i<n;i++)
		{
					for(j=0;j<m;j++)
					if(mat[i][j]==1)
					{	v[k++]=a[i];
						el++;}
		}
		FILE *g=fopen("cmlsc.out","w");
		fprintf(g,"%d \n",el);
		for(i=1;i<el;i++)		
					fprintf(g,"%d ",v[i]);
		fclose(g);			
		return el;
		
}


int main()
{
		int n,m;
		int *a,*b;
		/*if(argc<2)
		{
			fprintf(stderr,"Usage %s in file/n",argv[0]);
			exit(1);}*/
		int el;
		read(&n,&a,&m,&b);
		//print(a,b,n,m);
		el=elcomune(a,b,n,m);
		printf("nr de elemente comune este %d ",el);
		return 0;
	}
	
			
