#include <fstream>
using namespace std;

#define N 1024
#define max(a, b) ((a > b) ? a : b)

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int A[N], B[N], C[N][N], LCS[N];

int main()
{
	int n, m, i, j, len = 0;
	in >> n >> m;
	for (i = 1; i <= n; ++i)
		in >> A[i];
	for (i = 1; i <= m; ++i)
		in >> B[i];

	for (i = 1; i <= n; ++i)
		for (j = 1; j <= m; ++j)
			if (A[i] == B[j])
				C[i][j] = C[i-1][j-1] + 1;
			else C[i][j] = max(C[i][j-1], C[i-1][j]);
		
	out << C[n][m] << endl;

	for (i = n, j = m; i; )
		if (A[i] == B[j]) {
			LCS[len++] = A[i];
			--i;
			--j;
		} else if(C[i-1][j] < C[i][j-1]) --j;
				 else --i;
	
	for (i = len - 1; i >= 0; --i)
		out << LCS[i] << " ";

	return 0;
}