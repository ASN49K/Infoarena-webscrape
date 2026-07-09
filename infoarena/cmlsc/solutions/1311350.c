#include <stdio.h>
#include <stdlib.h>
//#define max(a,b) (a>b?a:b)

unsigned int max(unsigned int a,unsigned int b)
{
	if(a>b) return a;
	return b;
}
void read(FILE *stream, int v[],int n)
{
	int i;
	for(i=0;i<n;i++)
		fscanf(stream,"%d",&v[i]);
}

int lcs(int v1[], int n, int v2[], int m, int **buff)
{
	int i, j, k;
	unsigned int **memo = (unsigned int**)malloc((n+1)*sizeof(unsigned int*));
	for(i=0;i<=n;i++)
	{
		memo[i] = (unsigned int*)malloc((m+1)*sizeof(unsigned int));
		for(j=0;j<=m;j++)
			if(i==0 || j==0) memo[i][j]=0;
			else
			{
				if(v1[i-1]==v2[j-1])
					memo[i][j]=memo[i-1][j-1]+1;
				else if(v1[i-1]!=v2[j-1])
				{
					memo[i][j] = max(memo[i][j-1],memo[i-1][j]);
				}
			}
	}
	j=m;i=n;k=0;
	*buff = (int*)realloc(*buff,memo[n][m]*sizeof(int));
	while(i>0)
	{
		while(memo[i][j]==memo[i][j-1])	j--;
		while(memo[i][j]==memo[i-1][j]) i--;
		(*buff)[k++]=v1[i-1];
		if(memo[i-1][j-1]){ i--; j--; }
		else break;
	}
	k = memo[n][m];
	for(i=0;i<=n;i++)
		free(memo[i]);
	free(memo);
	return k;
}

int main()
{
	FILE *in = fopen("cmlsc.in","r"),*out = fopen("cmlsc.out","w");
	int n,m,i;
	int *v1=NULL,*v2=NULL,*buff=NULL,length;
	fscanf(in,"%d %d",&n,&m);
	v1 = (int*)malloc(n*sizeof(int));
	v2 = (int*)malloc(m*sizeof(int));
	read(in,v1,n);
	read(in,v2,m);
	length = lcs(v1,n,v2,m,&buff);
	fprintf(out,"%d\n",length);
	for(i=length-1;i>=0;i--)
		fprintf(out,"%d ",buff[i]);
	fprintf(out,"\n");
	free(v1);free(v2);
	fclose(in);fclose(out);free(buff);
	return 0;
}