#include<stdio.h>

#define MaxN 1100

int A[MaxN];
int B[MaxN];
int C[MaxN][MaxN];
int N;
int M;
FILE *g = fopen("cmlsc.out","w");

int max(int a,int b)
{
	return a>b ? a:b;
}

void afis(int i,int j)
{
	while(A[i] != B[j])
		if(C[i-1][j] == C[i][j])
			-- i;
		else
			-- j;
	if(i == 0 && j == 0)
		return ;
	else
	{
		afis(i-1,j-1);
		fprintf(g,"%d ",A[i]);
	}
}

int main()
{
	FILE *f = fopen("cmlsc.in","r");
	
	fscanf(f,"%d %d",&N,&M);
	for(int i=1;i<=N;i++)
		fscanf(f,"%d ",&A[i]);
	for(int j=1;j<=M;j++)
		fscanf(f,"%d ",&B[j]);
	
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
		{
			if(A[i] == B[j])
				C[i][j] = C[i-1][j-1] + 1;
			C[i][j] = max(C[i][j] , max(C[i-1][j] , C[i][j-1]));
		}
	fprintf(g,"%d\n",C[N][M]);
	
	afis(N,M);
	
	fclose(g);
	fclose(f);
}