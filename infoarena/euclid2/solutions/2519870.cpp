#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b)
{
	while (a != b)
		if (a > b)
			a -= b;
		else
			b -= a;
	return a;
}

int nr_perechi, nr1, nr2;

int main()
{
	fin >> nr_perechi;

	while (nr_perechi != 0)
	{
		fin >> nr1;
		fin >> nr2;
		fout << euclid(nr1, nr2) << "\n";
		nr_perechi--;
	}
	return 0;
}