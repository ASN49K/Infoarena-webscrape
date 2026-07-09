#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nim.in.in");
ofstream fout("nim.in.out");

int main() {
	int n, t;
	fin >> t;
	while (t--) {
        int tmp, s = 0;
        fin >> n;
        for (int i = 1; i <= n; i++) {
            fin >> tmp;
            s ^= tmp;
        }
        if (s)
            fout << "DA\n";
        else
            fout << "NU\n";
	}
	return 0;
}
