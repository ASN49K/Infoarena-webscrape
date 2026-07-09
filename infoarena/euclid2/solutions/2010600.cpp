#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
unsigned long a, b, T, r;

unsigned long euclid(unsigned long a, unsigned long b)
{
	while (b)
	{
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}
int main()
{
	fin >> T;
	for (unsigned long i = 1; i <= T; i++) { fin >> a >> b; fout << euclid(a, b) << endl; }
}