#include <fstream>
using namespace std;
#define DIM 1026

ifstream fi ("cmlsc.in");
ofstream fo ("cmlsc.out");

int M, N;
int A[DIM], B[DIM];
int D[DIM][DIM];
int S[DIM], NS;

int main ()
{
	int i, j;
	
	fi >> M >> N;
	for (i = 1; i <= M; ++i)
		fi >> A[i];
	for (i = 1; i <= N; ++i)
		fi >> B[i];
	
	for (i = 1; i <= M; ++i)
		for (j = 1; j <= N; ++j)
			if (A[i] == B[j])
				D[i][j] = D[i - 1][j - 1] + 1;
			else
				D[i][j] = max (D[i - 1][j], D[i][j - 1]);				
	
	i = M, j = N, NS = -1;
	while (D[i][j])
		if (A[i] == B[j])
			S[++NS] = A[i], --i, --j;
		else if (D[i][j - 1] > D[i - 1][j])
			--j;
		else
			--i;
	
	fo << NS + 1 << '\n';
	for (i = NS; i >= 0; --i)
		fo << S[i] << ' ';

	return 0;
}

