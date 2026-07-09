#include <cstdio>

#define MaxN 1050

int N,M,A[MaxN],B[MaxN],C[MaxN][MaxN],v[MaxN],nr;

void cit()
{
	int i;
	scanf("%d%d",&M,&N);
	for(i=1;i<=M;i++)
		scanf("%d",&A[i]);
	for(i=1;i<=N;i++)
		scanf("%d",&B[i]);
}

int max(int x,int y)
{
	return (x>y)? x:y;
}


void cmlsc()
{
	int i,j;
	for(i=1;i<=M;i++)
		for(j=1;j<=N;j++)
			if(A[i]==B[j])
				C[i][j]=1+C[i-1][j-1];
			else
				C[i][j]=max(C[i-1][j],C[i][j-1]);
	nr=0;
	i=M;j=N;
	while(i)
	{
		if(A[i]==B[j])
		{
			v[++nr]=A[i];
			i--;
			j--;
		}
		else
			if(C[i-1][j]<C[i][j-1])
				j--;
			else
				i--;
	}
}

void afis()
{
	printf("%d\n",nr);
	for(int i=nr;i>0;i--)
		printf("%d ",v[i]);
	printf("\n");
}

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	cit();
	cmlsc();
	afis();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
