#include <fstream>
#define INFILE "euclid2.in"
#define OUTFILE "euclid2.out"

using namespace std;

int gcd (int a, int b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	int min = a < b? a:b;
	int max = a > b? a:b;
	while (min != 0) {
		int aux = min;
		min = max % min;
		max = aux;
	}
	return max;
}
int main()
{
	int t, a, b;
	ifstream fin(INFILE);
	ofstream fout(OUTFILE);
	fin >> t;
	while (t--) {
		fin >> a >> b;
		fout << gcd(a,b) << endl;
	}
	fin.close();
	fout.close();
	return 0;
}