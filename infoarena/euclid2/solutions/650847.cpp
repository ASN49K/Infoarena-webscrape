#include <fstream>
#define INFILE "euclid2.in"
#define OUTFILE "euclid2.out"

using namespace std;

int gcd (int a, int b)
{
	int r;
	while (b != 0) {
		r = b;
		b = a % b;
		a = r;
	}
	return a;
}
int main()
{
	int t, a, b;
	ifstream fin(INFILE);
	ofstream fout(OUTFILE);
	fin >> t;
	while (t--) {
		fin >> a >> b;
		fout << gcd(a,b) << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}