#include <fstream>
#define NMAX 1027
#define MMAX 1027

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

short int M, N, A[NMAX], B[MMAX];
short int C[NMAX][NMAX], D[NMAX][NMAX];

inline int MAX(int a, int b)
{
	if (a > b) return a;
	else 	   return b;
}

void afiseaza_sir(int i, int j)
{
	if (i == 0||j == 0)
		return;
	
	if (D[i][j] == 1)
	{
		afiseaza_sir(i-1, j-1);
		fout <<A[i] <<' ';
	} 
	else
	{
		if (D[i][j] == 2)
			afiseaza_sir(i-1,j);
		else
			afiseaza_sir(i,j-1);
	}
}

int main()
{
	short int i, j;

	fin >>N >>M;
	
	for (i = 1; i <= N; i++)
		fin >>A[i];
	for (i = 1; i <= M; i++)
		fin >>B[i];
	
	for (i = 1; i <= N; i++)
		for (j = 1; j <= M; j++)
			if (A[i] == B[j])
			{
				C[i][j] = C[i-1][j-1] + 1;
				D[i][j] = 1;
			} else
			{
				if (C[i-1][j] > C[i][j-1])
				{
					C[i][j] = C[i-1][j];
					D[i][j] = 2;
				}
				else 
				{
					C[i][j] = C[i][j-1];
					D[i][j] = 3;
				}
			}
	fout <<C[N][M] <<'\n';		
	afiseaza_sir(N,M);
	fout.close();
	return 0;
		
}