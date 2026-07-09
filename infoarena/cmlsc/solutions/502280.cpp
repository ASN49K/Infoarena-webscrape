#include <stdio.h>

int i,j,N,M,nr,A[1025],B[1025],L[1025][1025],S[1025];

void citire()
{
	scanf("%d %d",&N,&M);
	for(i=1;i<=N;i++)
		scanf("%d",&A[i]);
	for(i=1;i<=M;i++)
		scanf("%d",&B[i]);
}

int max(int a,int b)
{
	if(a>b) return a;
	return b;
}

void pd()
{
	for(i=1;i<=N;i++)
		for(j=1;j<=M;j++)
			if(A[i]==B[j]) L[i][j]=1+L[i-1][j-1];
		else L[i][j]=max(L[i-1][j],L[i][j-1]);
}

void sir()
{
	i=N; j=M;
	while(i)
	{
		if(A[i]==B[j])
		{
			S[++nr]=A[i];
			i--; j--; 
		}
		else if(L[i-1][j]<L[i][j-1]) j--;
		else i--;
	}
}

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	citire();
	pd();
	sir();
	printf("%d\n",L[N][M]);
	for(i=nr;i;i--) printf("%d ",S[i]);
}