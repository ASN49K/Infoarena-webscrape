#include <fstream>
using namespace std;

int main()
{
	ifstream fin("nim.in");
	ofstream fout("nim.out");
	int t, n, a, xorsum;
	fin >> t;
	for (; t > 0; --t) {
		xorsum = 0;
		fin >> n;
		for (; n > 0; --n) {
			fin >> a;
			xorsum ^= a;
		}
		fout << (xorsum? "DA\n" : "NU\n");
	}
	return 0;
}
		
