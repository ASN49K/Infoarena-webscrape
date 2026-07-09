#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define max(a,b) ((a>b)?a:b)

int *v1, *v2;
int C[1050][1050];

FILE *input;
FILE *output;

void print(int a, int b,int count){
	if (a == 0 || b == 0)
	{
		fprintf(output, "%d\n", count);
		return;
	}
	else if (v1[a] == v2[b]){
		count++;
		print(a - 1, b - 1,count);
		fprintf(output, "%d ", v1[a]);
	}
	else if (C[a][b - 1] > C[a - 1][b]){
		print(a, b - 1,count);
	}
	else{
		print(a - 1, b,count);
	}


}


int main(){

	input = fopen("cmlsc.in", "r");
	output = fopen("cmlsc.out", "w");

	int m, n;
	fscanf(input, "%d %d", &m, &n);

	v1 = (int*)malloc(m*sizeof(int));
	v2 = (int*)malloc(n*sizeof(int));
	for (int i = 1; i <= m; i++)
	{
		fscanf(input, "%d", &v1[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		fscanf(input, "%d", &v2[i]);
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
	//fprintf(output, "%d\n", msx);
	//print out the subsequence
	print(m, n,0);
	return 0;
}