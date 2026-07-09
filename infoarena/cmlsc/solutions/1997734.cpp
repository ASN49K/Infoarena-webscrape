#include <fstream>
#include <vector>
using namespace std;

vector<short> kozos;

short max(short a, short b) {
	if (a > b) return a;
	return b;
}

short cmsc(short A[], short B[], short i, short j) {
	if (i == -1 || j == -1) return 0;
	if (A[i] == B[j]) {
		kozos.push_back(A[i]);
		return 1 + cmsc(A, B, i - 1, j - 1);
	}
	return max(cmsc(A, B, i - 1, j), cmsc(A, B, i, j - 1));
}

int main() {
	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");
	short N, M;
	in >> N >> M;

	short A[1024], B[1024];
	for (int i = 0;i < N;++i) in >> A[i];
	for (int i = 0;i < M;++i) in >> B[i];

	out << cmsc(A, B, N-1, M-1) << "\n";
}