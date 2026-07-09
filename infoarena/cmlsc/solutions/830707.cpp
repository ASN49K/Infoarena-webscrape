#include <iostream>
#include <fstream>
using namespace std;

#define MAX 1024
#define max(x, y) ((x)>(y)?(x):(y))

int M, N;
int A[MAX], B[MAX];		// cele doua siruri
int S[MAX+1][MAX+1];	// folosit pentru construirea solutiei


void print_solution(int i, int j)
{
	if (i == 0) 		return;
	else if (j == 0) 	return;
	else if (A[i-1] == B[j-1]) 		
	{
		print_solution(i-1, j-1);
		ofs << A[i-1] << " ";
	}
	else if (S[i-1][j] > S[i][j-1]) print_solution(i-1, j);
	else							print_solution(i, j-1);
}

int main()
{
	ifstream ifs("cmlsc.in");
	ofstream ofs("cmlsc.out");
	ifs >> M >> N;

	for (int i = 0; i < M; ++i) ifs >> A[i];
	for (int i = 0; i < N; ++i) ifs >> B[i];
	
	for (int k = 0; k <= M; ++k) S[k][0] = 0;
	for (int k = 0; k <= N; ++k) S[0][k] = 0;

	for (int i = 1; i <= M; ++i)
		for (int j = 1; j <= N; ++j)
		{		
			S[i][j] = max(S[i-1][j], S[i][j-1]);
			if (A[i-1] == B[j-1]) 
				S[i][j] = max(S[i][j], 1+S[i-1][j-1]);
		}

	ofs << S[M][N] << endl;
	print_solution(M, N);
	ofs << endl;

	ofs.close();
	ifs.close();
	return 0;
}

