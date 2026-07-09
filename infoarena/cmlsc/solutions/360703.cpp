#include <stdio.h>

int max(int x, int y)
{
	if(x >= y)
		return x;
	return y;
}

int main ()
{
	FILE *inFile = fopen("cmlsc.in", "r");
	FILE *outFile = fopen("cmlsc.out", "w");
	
	int N, M, A[1024], B[1024];
	int V[1025][1025];
	int S[1025];
	int noS;
	
	for(int i = 0; i < 1025; i++)
	{
		V[i][0] = 0;
		V[0][i] = 0;
	}
	fscanf(inFile, "%d%d", &N, &M);
	for(int i = 0; i < N; i++)
		fscanf(inFile, "%d", &A[i]);
	for(int i = 0; i < M; i++)
		fscanf(inFile, "%d", &B[i]);
	
	for(int i = 0; i < N; i++)
		for(int j = 0 ; j < M; j++)
		{
			if(A[i] == B[j])
				V[i+1][j+1] = V[i][j] + 1;
			else
				V[i+1][j+1] = max(V[i+1][j], V[i][j+1]);
		}
	
	int i = N ;
	int j = M;
	
	noS = V[i][j];
	fprintf(outFile, "%d\n", noS);
	int k = noS;
	if(noS != 0)
	{
		do
		{
			if(V[i][j] == V[i-1][j])
			{
				i--;
				continue;
			}
			if(V[i][j] == V[i][j-1])
			{
				j--;
				continue;
			}
			S[k] = A[i-1];
			k--;
			i--;
			j--;			
		}
		while(!(V[i-1][j] == 0 && V[i][j-1] == 0) && !(i == 0 && j == 0));
		S[k] = A[i-1];
		for(int i = 1; i <= noS; i++)
			fprintf(outFile, "%d ", S[i]);
	}
	fclose(inFile);
	fclose(outFile);
	
	return 0;
}
