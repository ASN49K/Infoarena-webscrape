#include <fstream>
using namespace std;
typedef unsigned int uint;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
uint a, b, T, r;

uint euclid(uint a, uint b)
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
	while(!fin.eof()) { fin >> a >> b; fout << euclid(a, b) << endl; }
        return 0;
}