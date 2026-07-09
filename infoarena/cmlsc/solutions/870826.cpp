#include <iostream>
#include <fstream>
#include <list>
using namespace std;

const int NMax = 1024;

inline void readArray(const int &n, int *a, istream &in = cin) {
	for (int i = 0; i < n; ++i)	in >> a[i];
}

int main() {
	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");

	int A[NMax], B[NMax], D[NMax][NMax];
	int N, M;

	in >> N >> M;

	readArray(N, A + 1, in);
	readArray(M, B + 1, in);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (A[i] == B[j])
				D[i][j] = D[i-1][j-1] + 1;
			else
				D[i][j] = max(D[i-1][j], D[i][j-1]);

	list<int> cls;

	for (int i = N, j = M, cnt = D[i][j]; cnt > 0;)
		if (A[i] == B[j])
			--cnt, cls.push_front(A[i]), --i, --j;
		else if (D[i - 1][j] == D[i][j])
			--i;
		else
			--j;

	out << D[N][M] << endl;

	list<int>::iterator it;
	for (it = cls.begin(); it != cls.end(); ++it)
		out << *it << " ";

	return 0;
}
