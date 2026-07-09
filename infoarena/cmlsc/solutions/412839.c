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
	
	*b=(int*)malloc((*m)*sizeof(int));
	for(i=0;i<(*m);i++)
			fscanf(f,"%i",&(*b)[i]);
	fclose(f);
	}	
		
int elcomune(int *a,int*b,int n,int m)
{
		int mat[256][256];
		int i,j;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				mat[i][i]=0;
		
		int v[256];
		int k=0,el=0;

		
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
					if(a[i]==b[j])
					{	if(i==0 || j==0)
							mat[i][j]=1;
						else 
							mat[i][j]=mat[i-1][j-1]+1;
						if(mat[i][j]>el)
						{		el=mat[i][j];
								k=0;
							}
						if(mat[i][j]==el)
								for(k=i-el+1;k<=i;k++)
									v[k-i+el-1]=a[i];
						 
					}	
		
		FILE *g=fopen("cmlsc.out","w");
		fprintf(g,"%d \n",el);
		for(i=0;i<el;i++)		
					fprintf(g,"%d ",v[i]);
		fclose(g);			
		return el;
		
}


int main()
{
		int n,m;
		int *a,*b;

		int el;
		read(&n,&a,&m,&b);
		
		el=elcomune(a,b,n,m);
		printf("nr de elemente comune este %d ",el);
		return 0;
	}
	
			
