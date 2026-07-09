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

	int A[20];
	for (i = 1; i <= M ; i++)
	{
		fin >> A[i];
	}
	
	int B[20];
	for (i = 1; i <= N; i++)
	{
		fin >> B[i];
	}

	int C[21][21];
	
	for (i = 0; i <= M; i++)
	{
		for (j = 0; j <= N; j++)
		{
			C[i][j] = 0;
		}
	}

	for (i = 1; i <= M; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (A[i] == B[j])
			{
				C[i][j] = C[i - 1][j - 1] + 1;
			}
			else
			{
				C[i][j] = max(C[i-1][j], C[i][j-1]);
			}
		}
	}
	//Afiseaza C
	for (i = 0; i <= M; i++)
	{
		for (j = 0; j <= N; j++)
		{
			cout << C[i][j] << " ";
		}
		cout << "\n";
	}
	
	int K = C[M][N];
	fout << K <<"\n";
	int V[20];
	i = M; j = N;
	while ((i>0)||(j>0))
	{
		if ((C[i][j] != C[i-1][j]) && (C[i][j] != C[i][j-1]))
		{
			V[K] = A[i];
			i--; j--; K--;
		}
		else if (C[i][j] == C[i - 1][j])
		{
			i--;
		}
		else if (C[i][j] == C[i][j - 1])
		{
			j--;
		}
	}
	for (i = 1; i <= C[M][N];i++)
	{
		fout << V[i] << " ";
	}
	
    return 0;

}


