// LongestCommon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
int *A,*B;

ofstream outFile("cmlsc.out");
ifstream inFile("cmlsc.in");

void commonSequence(int N,int M)
{

	int** aux = new int*[N+1];

	for (int i = 0; i <= N; i++)
	{
		aux[i] = new int[M+1];
	}

	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= M; j++)
			aux[i][j] = 0;
	
	
	for (int i = 1; i <= N; i++)
	{
		
		for (int j = 1; j <= M; j++)
		{
			if (A[i] == B[j])
				aux[i][j] = aux[i-1][j-1] + 1;
			else aux[i][j] = max(aux[i-1][j],aux[i][j-1]);
						
		}
	}

	outFile << aux[N][M] << "\n";
	int  i = N, j = M, chars = aux[N][M];
	int *c = new int[aux[N][M]];

	while (i >= 1 && j >= 1)
	{
		if (A[i] == B[j])
		{
			c[chars] = A[i];
			chars--;

			i--;
			j--;
		}
		else if (aux[i - 1][j] > aux[i][j - 1])
			i--;
		else j--;
	}

	for (int i = 1; i <= aux[N][M]; i++)
		outFile << c[i] << " ";
}




int _tmain(int argc, _TCHAR* argv[])
{
	int N, M;
	inFile >> N >> M;

	
	A = new int[N+1];
	B = new int[M+1];

	for (int i = 1; i <= N; i++)
		inFile >> A[i];
	

	for (int j = 1; j <= M; j++)
		inFile >> B[j];



	commonSequence(N, M);

	return 0;
}

