#include <fstream>
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

#define nmax 10001

int i, j, t, n;
int x, S;

int main() {
	fin >> t;
	
	while (t--) {
		fin >> n;
		for (i = 1; i <= n; ++i) {
			fin >> x;
			S ^= x;
		}
		if (S) fout << "DA\n";
		else 
			fout << "NU\n";
	}
	return 0;
}
