// Cel mai lung subsir comun.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#define DIM 1026
std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");
using namespace std;

int n, A[DIM], m, B[DIM];
int M[DIM][DIM];

void Read(int v[], int& n)
{
	for (int i = 1; i <= n; i++)
		fin >> v[i];
}

void CMLSC()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (A[i] == B[j])
				M[i][j] = M[i - 1][j - 1] + 1;
			else
				M[i][j] = max(M[i - 1][j], M[i][j - 1]);
	fout << M[n][m] << "\n";
}

void Traseu()
{
	vector<int> V;
	int i = n, j = m;
	while (i >= 1 && j >= 1)
	{
		if (A[i] == B[j])
			V.push_back(A[i]);
		if (M[i][j] == M[i - 1][j])
			i--;
		else
			j--;
	}
	while (!V.empty())
	{
		fout << V.back() << " ";
		V.pop_back();
	}
}

int main()
{
	fin >> n >> m;
	Read(A, n);
	Read(B, m);
	CMLSC();
	Traseu();
	return 0;
}