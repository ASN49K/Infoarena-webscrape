#include <stdio.h>

#define NMAX 1024

int N,M,A[NMAX],B[NMAX];
int X[NMAX][NMAX];

void afisare(int x, int y)
{
	if ((X[x][y] == 0) || (x < 0) || (y<0) )
		return;
	if (A[x] == B[y])
	{
		afisare(x-1,y-1);
		printf("%d ",A[x]);
		return;
	}

	if (X[x][y] == X[x-1][y])
	{
		afisare(x-1,y);
		return;
	}

	if (X[x][y] == X[x][y-1])
	{
		afisare(x,y-1);
		return;
	}
	
}

void print()
{
	printf("%d\n",X[N-1][M-1]);
	afisare(N-1,M-1);
}

void cmlsc()
{
	int i,j;

	X[0][0] = (A[0] == B[0] ? 1:0);

	for (j=0;j<M;j++)
		X[0][j] = (A[0] == B[j] || X[0][j-1] ? 1:0);

	for (i=1;i<N;i++)
	{
		X[i][0] = (A[i] == B[0] || X[i-1][0] ? 1:0);
		for (j=1;j<M;j++)
		{
			if (A[i] == B[j])
				X[i][j] = X[i-1][j-1] + 1;
			
			if (X[i][j] < X[i-1][j])
				X[i][j] = X[i-1][j];
			
			if (X[i][j] < X[i][j-1])
				X[i][j] = X[i][j-1];
		}
	}
	print();
}

int main()
{
	int i,j;
	freopen("cmlsc.in", "rt", stdin);
	freopen("cmlsc.out", "wt", stdout);

	scanf("%d %d",&N,&M);

	for (i=0;i<N;i++)
		scanf("%d",&A[i]);

	for (i=0;i<M;i++)
		scanf("%d",&B[i]);

	cmlsc();
	return 0;
}
