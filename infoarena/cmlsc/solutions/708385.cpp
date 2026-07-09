#include <cstdio>

#define maxim(a, b) ((a > b) ? a : b)
#define NMax 1090

long M, N, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], bst;

int main()
{
    
    freopen("cmlsc.in", "rt", stdin);
    freopen("cmlsc.out", "wt", stdout);

    scanf("%ld %ld", &N, &M);

    for(long i=1;i<=N;i++)
        scanf("%ld", &A[i]);

    for(long j=1;j<=M;j++)
        scanf("%ld", &B[j]);

	for(long i=1;i<=N;i++)
		for(long j=1;j<=M;j++)
			if(A[i] == B[j])
				D[i][j] = 1 + D[i-1][j-1];
			else
				D[i][j] = maxim(D[i-1][j], D[i][j-1]);

	long i=N,j=M;

    while(i)
        if (A[i] == B[j])
             sir[++bst]=A[i],i--, j--;
        else 
			if (D[i-1][j] < D[i][j-1])
				j--;
			else
				i--;

    printf("%ld\n", bst);
    i = bst;
	while(i)
        printf("%ld ", sir[i]),--i;

    return 0;
}


