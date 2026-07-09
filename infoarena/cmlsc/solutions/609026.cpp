#include <fstream>

#define max(a, b)	a > b ? a : b
#define MAX_LEN 1025


short int A[MAX_LEN], B[MAX_LEN];
// The matrix used for the computation of the LCS
short int matrix[MAX_LEN][MAX_LEN];

std::ifstream ifs("cmlsc.in");
std::ofstream ofs("cmlsc.out");


// Computes the length of the LCS
int LCS( int m, int n );

// Computes one of the possible LCS and print's it to the file
void backTrackLCS( int m, int n );


int main()
{
	// This variables hold the effective length of the two arrays
	int m, n;
	int i;

	ifs >> m >> n;

	for (i = 1; i <= m; ++i) {
		ifs >> A[i];
	}

	for (i = 1; i <= n; ++i) {
		ifs >> B[i];
	}

	ofs << LCS(m, n) << "\n";
	backTrackLCS(m, n);

	return 0;
}

int LCS( int m, int n )
{
	int i, j;

	for (i = 1; i <= m; ++i) {
		for (j = 1; j <= n; ++j) {
			if (A[i] == B[j]) {
				matrix[i][j] = matrix[i - 1][j - 1] + 1;
			}else {
				matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
			}
		}
	}

	return matrix[m][n];
}


void backTrackLCS( int m, int n ) 
{
	if (m == 0 || n == 0) {
		// do nothing (base case)
	}else if(A[m] == B[n]) {
		backTrackLCS(m - 1, n - 1);
		ofs << A[m] << " ";
	}else {
		if (matrix[m - 1][n] > matrix[m][n - 1]) {
			backTrackLCS(m - 1, n);
		}else {
			backTrackLCS(m, n - 1);
		}
	}
}