#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void read(char *filename,int *n,int **a,int *m,int **b)
{
	FILE *f=fopen(filename,"r");
	int i;
	fscanf(f,"%d",n);
	*a=(int*) malloc((*n)*sizeof(int));
	for(i=0;i<(*n);i++)
			fscanf(f,"%i",&(*a)[i]);
	fscanf(f,"%d",m);
	*b=(int*)malloc((*m)*sizeof(int));
	for(i=0;i<(*m);i++)
			fscanf(f,"%i",&(*b)[i]);
	fclose(f);
	}	
void print(int *a,int *b,int n,int m)
{
	FILE *g=fopen("out.txt","w");
	
	int i=0;
	for(i=0;i<n;i++)
		fprintf(g,"%d ",a[i]);
	fprintf(g,"\n");
	for(i=0;i<m;i++)
			fprintf(g,"%d ",b[i]);
	fclose(g);
}			
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
				
		for(i=0;i<n;i++)
		{
					for(j=0;j<m;j++)
					if(mat[i][j]==1)
						printf("%d ",a[i]);
					printf("\n");
		}				
		return el;
}


int main(int argc,char **argv)
{
		int n,m;
		int *a,*b;
		if(argc<2)
		{
			fprintf(stderr,"Usage %s in file/n",argv[0]);
			exit(1);}
		int el;
		read(argv[1],&n,&a,&m,&b);
		print(a,b,n,m);
		el=elcomune(a,b,n,m);
		printf("nr de elemente comune este %d ",el);
		return 0;
	}
	
			
