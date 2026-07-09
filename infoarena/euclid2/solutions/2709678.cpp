#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T, a, b;

int main()
{
	fin >> T;
	for (int i = 1; i <= T; ++i)
	{
		fin >> a >> b;
		while (b)
		{
			int r = a % b;
			a = b;
			b = r;
		}
		fout << a << '\n';
	}
	return 0;
}



