#include <fstream>
#define NMAX 1026

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

void citire();
void pd();
void afisare();

int n, m;
int A[NMAX], B[NMAX];
int LCS[NMAX][NMAX];
int main()
{
	citire();
	pd();
	afisare();
	return 0;
}

void citire()
{
	int i;
	fin >> n >> m;
	for (i = 1; i <= n; i ++)
		fin >> A[i];
	for (i = 1; i <= m; i ++)
		fin >> B[i];
}

void pd()
{
	int i, j;
	for (i = n; i > 0; i --)
		for (j = m; j > 0; j --)
		{
			if (A[i] == B[j])
				LCS[i][j] = 1 + LCS[i+1][j+1];
			else
				if (LCS[i][j+1] > LCS[i+1][j])
					LCS[i][j] = LCS[i][j+1];
				else
					LCS[i][j] = LCS[i+1][j];
		}
}

void afisare()
{
	int i, j;
	fout << LCS[1][1] << '\n';
	i = 1; j = 1;
	while (i <= n && j <= m)
	{
		if (A[i] == B[j])
		{
			fout << A[i] << ' ';
			i ++; j ++;
		}
		else
			if (LCS[i][j] == LCS[i+1][j])
				i ++;
			else
				j ++;
	}
	fout << '\n';
}
