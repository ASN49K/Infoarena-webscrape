/*
	http://www.infoarena.ro/problema/euclid2
*/

#define INPUT "euclid2.in"
#define OUTPUT "euclid2.out"

#include <fstream>
using namespace std;

inline int cmmdc(int a, int b)
{
	return (b == 0) ? a : cmmdc(b, a % b);
}

int main()
{
	ifstream fin(INPUT);
	ofstream fout(OUTPUT);
	int T, a, b;
	fin >> T;
	while (T--)
	{
		fin >> a >> b;
		fout << cmmdc(a, b) << "\n";
	}
	fout.close();
	fin.close();
	return 0;
}