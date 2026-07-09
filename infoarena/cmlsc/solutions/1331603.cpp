/* Se dau doi vectori A si B cu elemente numere naturale nenule.
Sa se determine subsirul de lungime maxima care apare atat in A cat si in B.*/
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

#define maxim(a, b) ((a >= b) ? a : b)
#define NMax 1024

int M, N, A[NMax], B[NMax], C[NMax][NMax], answer[NMax], answer_length;

void print_solution(int C[][NMax], int A[NMax], int B[NMax], int i, int j)
{
	ofstream outFile;
	outFile.open("cmlsc.out", ios::app);

	if (i == 0 || j == 0)
		return;
	else if (A[i] == B[j])
	{
		print_solution(C, A, B, i - 1, j - 1);
		outFile << A[i] << " ";
	}
	else
	{
		if (C[i - 1][j] >= C[i][j - 1])
			print_solution(C, A, B, i - 1, j);
		else
			print_solution(C, A, B, i, j - 1);
	}
}

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

	/*for (i = 0; i <= M; i++)
		C[i][0] = 0;
	for (j = 0; j <= N; j++)
		C[0][j] = 0;*/

	for (i = 1; i <= M; i++)
		for (j = 1; j <= M; j++)
			if (A[i] == B[j])
				C[i][j] = C[i - 1][j - 1] + 1;
			else
				C[i][j] = maxim(C[i - 1][j], C[i][j - 1]);

	outFile << C[M][N] << endl;
	print_solution(C, A, B, M, N);
}