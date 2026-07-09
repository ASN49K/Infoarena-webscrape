#include <fstream>
#include <vector>
#include <iterator>
using namespace std;

short max(short a, short b) {
	if (a > b) return a;
	return b;
}

int main() {
	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");
	short N, M;
	in >> N >> M;

	short* A = new short[N+1];
	short* B = new short[M+1];

	for (int i = 1;i <= N;++i) in >> A[i];
	for (int i = 1;i <= M;++i) in >> B[i];

	short** tomb = new short*[N+1];
	for (int i = 0;i <= N;++i)
		tomb[i] = new short[M+1];
	
	for (int i = 0;i <= N;++i) tomb[i][0] = 0;
	for (int i = 1;i <= M;++i) tomb[0][i] = 0;

	vector<short> kozos;

	for (int i = 1;i <= N;++i) 
		for (int j = 1;j <= M;++j) 
			if (A[i] == B[j]) {
				tomb[i][j] = tomb[i - 1][j - 1] + 1;
				kozos.push_back(A[i]);
			}
			else tomb[i][j] = max(tomb[i - 1][j], tomb[i][j - 1]);

	out << tomb[N][M] << "\n";
	for (vector<short>::iterator it=kozos.begin(); it != kozos.end(); it++) {
		out << *it << " ";
	}
}