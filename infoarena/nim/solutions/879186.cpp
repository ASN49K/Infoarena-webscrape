#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ifstream fin("nim.in");
	ofstream fout("nim.out");
	int ntest; fin >> ntest;
	for (int i=0; i<ntest; ++i) {
		int n, xorsum=0;
		fin >> n;
		for (int j=0,pile; j<n; ++j) {
			fin >> pile;//stone in pile j
			xorsum^=pile;
		}
		if (xorsum==0) fout << "NU\n";
		else fout << "DA\n";
	}
	return 0;
}
