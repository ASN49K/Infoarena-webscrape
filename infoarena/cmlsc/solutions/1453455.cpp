#include <stdio.h>

#define max(a, b) ((a > b) ? a : b)

int main(){
	int X[1025], Y[1025], Z[1025][1025], result[1025];
	int M, N, i, j, k;
	
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);

	scanf("%d %d", &N, &M);

	for(i=1; i<=N; i++)
		scanf("%d ", &X[i]);
	for(j=1; j<=M; j++)
		scanf("%d ", &Y[j]);

	for(i=0; i<=N; i++)
		for(j=0; j<=M; j++){
			if((i == 0) || (j == 0))
				Z[i][j] = 0;
			else {
				if(X[i] == Y[j])
					Z[i][j] = Z[i-1][j-1] + 1;
				else
					Z[i][j] = max(Z[i][j-1], Z[i-1][j]);
			}
		}

	i = N; j = M;
	k=0;
	while((i>0) && (j>0)){
		if(X[i] == Y[j]){
			result[k] = X[i];
			k++;
			i--;
			j--;
		} else if (Z[i][j-1] > Z[i-1][j]){
				j--;
		} else 
			i--;
	}		

	for(i=k-1; i>=0; i--)
		printf("%d ", result[i]);
	
	return 0;
}

