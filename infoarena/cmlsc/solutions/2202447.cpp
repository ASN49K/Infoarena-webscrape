#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>

using namespace std;


FILE*in=fopen("cmlsc.in", "r");
FILE*out=fopen("cmlsc.out", "w");

void cel_mai_lung_subsir_comun(int A[], int B[], int M, int N)
{
	int cmax = 0, c=0,pozA=0,i=0,j=0;
	while (i < M)
	{
		
		while (j < N)
		{
			if (A[i] == B[j])
			{
				c++;
				if (cmax < c)
				{
					cmax = c;
					pozA = i;
				
				}
				i++;
				j++;
			}
			else
			{
				c = 0;
				j++;

			}

		}
		i++;
		j = 0;
	}
	fprintf(out,"%d\n", cmax);
	for (int i=cmax-1;i>=0;i--)
		fprintf(out,"%d", A[pozA-i]);

}


int main(void)
{
	int M, N, A[256], B[256];
	fscanf(in,"%d",&M);
	fscanf(in,"%d", &N);

	for (int i = 0; i < M; i++)
		fscanf(in,"%d", &A[i]);
	for (int i = 0; i < N; i++)
		fscanf(in,"%d", &B[i]);

	cel_mai_lung_subsir_comun(A, B, M, N);
	return 0;
	
}