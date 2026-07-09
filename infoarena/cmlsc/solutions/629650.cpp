#include<iostream>
#include<stdio.h>
#define FOR(i, a, b) for (i = a; i <= b; ++i)
#define NMax 1024
#define maxim(a, b) ((a > b) ? a : b)

 int M,N,bst,A[NMax],B[NMax],d[NMax][NMax],sir[NMax];
int main(void)
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	int i,j;
	scanf("%d%d",&M,&N);
	for(i=1;i<=M;i++)
		scanf("%d",&A[i]);
	for(j=1;j<=N;j++)
		scanf("%d",&B[j]);
	for(i=1;i<=M;i++)
		for(j=1;j<=N;j++)
			{
				d[i][j] = maxim(d[i-1][j], d[i][j-1]);
				if(A[i]==B[j])
				d[i][j]=maxim(d[i][j],1+d[i-1][j-1]);
		}
				
	for(i=M,j=N;i;)
		if(A[i]==B[j])
			sir[++bst] = A[i], --i, --j;
		else if (d[i-1][j] < d[i][j-1])
			--j;
		else
			--i;
		printf("%d\n", bst);
		for (i = bst; i; --i)
			printf("%d ", sir[i]);
	return 0;
}