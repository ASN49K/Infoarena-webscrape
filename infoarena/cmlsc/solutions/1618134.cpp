// Cel mai lung subsir comun.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <fstream>
#define max(a,b) (((a) > (b)) ? (a) : (b))
using namespace std;
int main()
{
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");

	int N, i,k=1,j, M;
	
	fin >> M; fin >> N;		//N,M

	int* A = new int[M];	//A
	for (i = 0; i < M; i++)
	{
		fin >> A[i];
	}
	
	int* B = new int[N];	//B
	for (i = 0; i < N; i++)	//B
	{
		fin >> B[i];
	}

	int* C = new int[(M+1)*(N+1)];	//C
	for (i = 0; i < (N + 1)*(M + 1); i++)
	{
		C[i] = 0;
	}
	
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (A[i] == B[j])
			{
				C[(j + 1)*(M + 1) + (i + 1)] = C[j*(M + 1) + i] + 1;
			}
			else
			{
				C[(j + 1)*(M + 1) + (i + 1)] = max(C[(j+1)*(M+1)+i], C[j*(M+1)+(i+1)]);
			}
		}
	}
	//Afiseaza C
	/*for (i = 0; i < (N + 1)*(M + 1); i++)	
	{
		cout << C[i];
		if (i == k*(M + 1) - 1)
		{
			k++;
			cout << "\n";
		}
	}
	*/
	int K = C[(M+1)*(N+1)-1];
	fout << K<<"\n";
	k = K-1;
	int* V = new int[K];
	i = M-1; j = N-1;
	while ((i>0)||(j>0))
	{
		if ((C[(j + 1)*(M + 1) + (i + 1)] != C[(j + 1)*(M + 1) + i]) && (C[(j + 1)*(M + 1) + (i + 1)] != C[j*(M + 1) + (i + 1)]))
		{
			V[k] = A[i];
			i--; j--; k--;
		}
		else if (C[(j + 1)*(M + 1) + (i + 1)] = C[(j + 1)*(M + 1) + i])
		{
			i--;
		}
		else if (C[(j + 1)*(M + 1) + (i + 1)] = C[j*(M + 1) + (i + 1)])
		{
			j--;
		}
	}
	for (i = 0; i < K;i++)
	{
		fout << V[i] << " ";
	}
	
    return 0;

}


