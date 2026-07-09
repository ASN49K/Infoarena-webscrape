#include <stdio.h>

#define MaxN 1026

int C[MaxN][MaxN], N, M, A[MaxN], B[MaxN], v[MaxN];

int max(int x, int y){
	if(x > y)
		return x;
	else
		return y;
}

int main(){
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	int i, j, k;
	scanf("%d %d", &M, &N);
	for(i = 1; i <= M; i++)
		scanf("%d", &A[i]);
	for(i = 1; i <= N; i++)
		scanf("%d", &B[i]);

	for(i = 1; i <= M; i++)
		for(j = 1; j <= N; j++)
			if(A[i] == B[j])
				C[i][j] = 1 + C[i-1][j-1];
			else
				C[i][j] = max(C[i-1][j], C[i][j-1]);
	printf("%d\n", C[M][N]);
	i = M;
	j = N;
	k = 0;
	while( i && j){
		if(A[i] == B[j]){
			v[k++] = A[i];
			i--;
			j--;
		}
		else
			while(A[i] != B[j] && i && j){
				if(C[i][j] == C[i-1][j])
					i--;
				else
					j--;
			}
	}
	for(i = k - 1; i >= 0; i--)
		printf("%d ", v[i]);
	printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
