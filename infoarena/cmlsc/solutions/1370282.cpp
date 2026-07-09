#include <fstream>

using std::ifstream;
using std::ofstream;

int main() {
	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");
	
	unsigned short M, N, aux;
	unsigned short *A, *B, C[1024], *AUX;
	unsigned short MAX = 0;
	int j = 0, k;
	
	in >> M >> N;
	A = new unsigned short[M];
	B = new unsigned short[N];

	for (int i = 0; i < M; ++i) {
		in >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		in >> B[i];
	}
	
	if (N > M) {
		aux = N;
		N = M;
		M = N;
		
		AUX = A;
		A = B;
		B = AUX;
	}
	
	for (int i = 0; i < M; ++i) {
		k = j;
		while (k < N) {
			if (B[k] == A[i]) {
				C[MAX++] = A[i];
				j = k;
				break;
			}
			++k;
		}
	}
	
	out << MAX << '\n';
	for (int i = 0; i < MAX; ++i) {
		out << C[i] << ' ';
	}

	out.flush();
	in.close();
	out.close();
	
	return 0;
}