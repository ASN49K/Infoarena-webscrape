#include <fstream>
#include <vector> // for vector
#include <algorithm> // for copy() and assign()
#include <iterator> // for back_inserter

using namespace std;

void f(const vector<int>& A, int N, const vector<int>& B, int M, vector<int>& out) {
	if (N == 0 || M == 0) {
		out.clear();
		return;
	}

	if (A[N - 1] == B[M - 1]) {
		f(A, N - 1, B, M - 1, out);	
		out.push_back(A[N - 1]);
	} else {
		vector<int> p1, p2;
		f(A, N - 1, B, M, p1);
		f(A, N, B, M - 1, p2);
		
		if (p1.size() >= p2.size()) {
		    copy(p1.begin(), p1.end(), back_inserter(out));
		} else {
		    copy(p2.begin(), p2.end(), back_inserter(out));
		}
	}
}

int main() {
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");

	int N, M;
	fin >> N >> M;
	vector<int> A, B;

	for (int i = 0; i < N; ++i) {
		int x;
		fin >> x;
		A.push_back(x);
	}

	for (int i = 0; i < M; ++i) {
		int x;
		fin >> x;
		B.push_back(x);		
	}

	vector<int> solution;
	f(A, N, B, M, solution);

	fout << solution.size() << "\n";
	for (int i = 0; i < solution.size(); ++i) {
		fout << solution[i] << " ";
	}

	fin.close();
	fout.close();

	return 0;
}