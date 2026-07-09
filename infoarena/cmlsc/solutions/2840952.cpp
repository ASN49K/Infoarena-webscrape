#include <fstream>
#include <vector> // for vector
#include <algorithm> // for copy() and assign()
#include <iterator> // for back_inserter

using namespace std;

void f(const vector<int>& A, const vector<int>& B, vector<int>& out) {
	if (A.size() == 0 || B.size() == 0) {
		out.clear();
		return;
	}

	if (A.back() == B.back()) {
		f(vector<int>(A.begin(), A.begin() + A.size() - 1), vector<int>(B.begin(), B.begin() + B.size() - 1), out);	
		out.push_back(A.back());
	} else {
		vector<int> p1, p2;
		f(vector<int>(A.begin(), A.begin() + A.size() - 1), B, p1);
		f(vector<int>(A, vector<int>(B.begin(), B.begin() + B.size() - 1), p2);
		out.clear();
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
	f(A, B, solution);

	fout << solution.size() << "\n";
	for (int i = 0; i < solution.size(); ++i) {
		fout << solution[i] << " ";
	}

	fin.close();
	fout.close();

	return 0;
}