/* Se dau doi vectori A si B cu elemente numere naturale nenule.
Sa se determine subsirul de lungime maxima care apare atat in A cat si in B.*/
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

#define maxim(a, b) ((a > b) ? a : b)
#define NMax 1024

int M, N, A[NMax], B[NMax], C[NMax][NMax], answer[NMax], answer_length = 0;

int main(void)
{
	ifstream inFile("cmlsc.in");
	ofstream outFile("cmlsc.out");

	inFile >> M >> N;

	int i, j;
	for (i = 1; i <= M; i++)
		inFile >> A[i];
	for (j = 1; j <= N;j++)
		inFile >> B[j];

	for (i = 1; i <= M; i++)
		for (j = 1; j <= N; j++)
			if (A[i] == B[j])
				C[i][j] = C[i - 1][j - 1] + 1;
			else
				C[i][j] = maxim(C[i - 1][j], C[i][j - 1]);

	for (i = M, j = N; i;)
	{
		if (A[i] == B[j])
		{
			answer[++answer_length] = A[i];
			i--;
			j--;
		}
		else
		{
			if (C[i - 1][j] < C[i][j - 1])
				j--;
			else
				i--;
		}
	}

	outFile << answer_length << endl;
	for (i = answer_length; i ; i--)
		outFile << answer[i] << " ";
}