/*
*The Longest common subsequence of 2 integer vectors using Dynamic programming
*Time complexity: O(M*N) M-size of array 1 ,N-size of array 2
*Space complexity: O(M*N)
*Start date: 12:09:2016 13:30
*/

#include <stdio.h>
#include <stdlib.h>
#define max(a,b) ((a>b)?a:b)


void read_vectors(int **v1,int **v2,int *m,int *n)
{
	FILE *fd;
	int i;
	fopen_s(&fd,"input.txt","r");
	if(fd==NULL)
	{
		perror("Error at opening the file.\n");
		exit(2);
	}
	if(fscanf_s(fd,"%d %d",m,n)!=2)
	{
		perror("Error at reading the sizes of the arrays.");
		exit(2);
	}
	if((*v1=(int*)malloc(sizeof(int)*(*m)))==NULL)
	{
		perror("Error at allocating memory.\n");
		exit(2);
	}
	if((*v2=(int*)malloc(sizeof(int)*(*n)))==NULL)
	{
		perror("Error at allocating memory.\n");
		exit(2);
	}
	for(i=0;i<*m;i++)
	{
		if(fscanf_s(fd,"%d ",&(*v1)[i])!=1)
		{
			perror("Error at reading the numbers.\n");
			exit(2);
		}
	}
	for(i=0;i<*n;i++)
	{
		if(fscanf_s(fd,"%d ",&(*v2)[i])!=1)
		{
			perror("Error at reading the numbers.\n");
			exit(2);
		}
	}
	fclose(fd);
}

void print_vector(int*v,int n)
{
	int i;
	printf("The content of the vector of size:%d is:\n",n);
	for(i=0;i<n;i++)
	{
		printf("%d ",v[i]);
	}
	printf("\n");
}
void longest_common_subsequence(int v1[],int v2[],int m,int n,int **result,int *size)
{
	int i,j,rows,columns,k;
	int **table;
	rows=m+1;
	columns=n+1;
	if((table=(int**)malloc(sizeof(int*)*rows))==NULL)
	{
		perror("Error at allocating memory.\n");
		exit(2);
	}
	for(i=0;i<rows;i++)
	{
		if((table[i]=(int*)malloc(sizeof(int)*columns))==NULL)
		{
			perror("Error at allocating memory.\n");
			exit(2);
		}
	}
	for(i=0;i<rows;i++)
	{
		table[i][0]=0;
	}
	for(j=0;j<columns;j++)
	{
		table[0][j]=0;
	}

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(v1[i]==v2[j])
			{
				table[i+1][j+1]=table[i][j]+1;
			}else{
				table[i+1][j+1]=max(table[i+1][j],table[i][j+1]);
			}
		}
	}
	*size=table[m][n];
	if((*result=(int*)malloc(sizeof(int)*(*size)))==NULL)
	{
		perror("Error at allocating memory.");
		exit(2);
	}
	i=m-1;j=n-1;
	k=*size;
	while(i>=0 && j>=0)
	{
		if(v1[i]==v2[j])
		{
			(*result)[--k]=v1[i];
			i--;
			j--;
		}else if(table[i][j+1]<table[i+1][j])
		{
			j--;
		}else{
			i--;
		}
	}
}

int main(int argc,char*argv[])
{
	int *v1,*v2,*result,sizeResult,m,n;
	read_vectors(&v1,&v2,&m,&n);
	longest_common_subsequence(v1,v2,m,n,&result,&sizeResult);
	print_vector(result,sizeResult);
	return 0;
}