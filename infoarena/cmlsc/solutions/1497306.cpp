#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define max(a,b) ((a>b)?a:b)

int *v1, *v2;
int C[1050][1050];

FILE *input;
FILE *output;

void print(int a, int b){
	if (a == 0 || b == 0){
		return;
	}
	else if (v1[a] == v2[b]){
		print(a - 1, b - 1);
		printf("%d ", v1[a]);
	}
	else if (C[a][b - 1] > C[a - 1][b]){
		print(a, b - 1);
	}
	else{
		print(a - 1, b);
	}


}


int main(){

	input = freopen("cmlsc.in", "r",stdin);
	output = freopen("cmlsc.out", "w",stdout);

	int m, n;
	fscanf(input, "%d %d", &m, &n);

	v1 = (int*)malloc(m*sizeof(int));
	v2 = (int*)malloc(n*sizeof(int));
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &v1[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &v2[i]);
	}

	for (int i = 0; i <= m; i++)
	{
		C[0][i] = 0;
	}
	for (int j = 0; j <= n; j++)
	{
		C[j][0] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{

			if (v1[i] == v2[j])
			{
				C[i][j] = C[i - 1][j - 1] + 1;
			}
			else{
				C[i][j] = max(C[i][j - 1], C[i - 1][j]);
			}
		}
	}

	//print  out the nr of the longest common subseq
    printf("%d\n", C[m][n]);
	//print out the subsequence
	print(m, n);
	return 0;
}