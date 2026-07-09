#include <fstream>

using namespace std;

int t, n, a, xorsum;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
	fin >> t;

	while (t--){
		fin >> n;

		xorsum = 0;
		while (n--){
			fin >> a;
			xorsum ^= a;
		}

		if (xorsum)
			fout << "DA\n";
		else
			fout << "NU\n";
	}

	return 0;
}