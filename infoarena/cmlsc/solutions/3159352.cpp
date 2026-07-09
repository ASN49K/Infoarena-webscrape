#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const string FILE_NAME = "cmlsc";
const string input = FILE_NAME + ".in";
const string output = FILE_NAME + ".out";

ifstream fin(input);
ofstream fout(output);

//vector<int>X = { 1, 5, 3, 9, 4, 6 };
//vector<int>Y = { 5, 6, 9, 2, 6 };
vector<int>X, Y, S, CMLSC;

// CMLSC(X, Y) = {5, 9, 6}

bool subsir(int nivel)
{
	// S={1, 5, 8}
	int l = 0, last=0;

	for (int i : S) {
		for (int j = last; j < Y.size(); j++) {
			if (X[i] == Y[j]) {
				last = j;
				l++;
				break;
			}
		}
	}
	
	return l == S.size();
}

bool ok(int nivel) {
	if (nivel == 0) return true;
	return S[nivel - 1] < S[nivel];
}

void back(int nivel)
{
	for (int i = 0; i < X.size(); i++) {
		S.push_back(i);

		if (ok(nivel)) {
			if (subsir(nivel)) {
				if (S.size() > CMLSC.size()) {
					CMLSC = S;
				}

				back(nivel + 1);
			}
		}

		S.pop_back();
	}
}

int main()
{
	int n, m;
	fin >> n >> m;

	X = vector<int>(n);
	Y = vector<int>(m);

	for (int i = 0; i < n; i++) fin >> X[i];
	for (int i = 0; i < m; i++) fin >> Y[i];

	back(0);

	fout << CMLSC.size() << '\n';
	for (int i : CMLSC) {
		fout << X[i] << ' ';
	}

	return 0;
}