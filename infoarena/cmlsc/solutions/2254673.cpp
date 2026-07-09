#include<fstream>
#define MAXM 1025
#define max(a, b) ((a > b) ? a : b)

using namespace std;

int A[MAXM], B[MAXM], D[MAXM][MAXM], sol[MAXM];

int main() {
	
	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");	
	
	int M, N, i, j;
	
	in >> M >> N;
	
	for (i = 1; i <= M; i++) {
		in >> A[i];
	}
	
	for (i = 1; i <= N; i++) {
		in >> B[i];
	}

	for (i = 1; i <= M; i++) {
		for (j = 1; j <= N; j++) {
			if (A[i] == B[j]) {
				D[i][j] = 1 + D[i - 1][j - 1];
			} else {
				D[i][j] = max(D[i - 1][j], D[i][j - 1]);
			}
		}
	}

	int count = 0;

	for (i = M, j = N; i > 0; ) {
		if (A[i] == B[j]) {
			sol[count++] = A[i];
			i--;
			j--;
		} else if (D[i - 1][j] > D[i][j - 1]) {
			i--;
		} else {
			j--;
		}
	}

	out << count << endl;
	for (i = count - 1; i >= 0; i--) {
		out << sol[i] << " ";
	}

	return 0;
}
