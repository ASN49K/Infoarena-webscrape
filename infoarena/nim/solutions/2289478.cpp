#include <fstream>

using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

int teste;
long long rezultat;

void Solve()
{
	in >> teste;
	for (int test = 1; test <= teste; test++)
	{
		int numere, nr;
		in >> numere;
		rezultat = 0;
		for (int i = 1; i <= numere; i++)
		{
			in >> nr;
			rezultat = (rezultat ^ nr);
		}
		if (rezultat) out << "DA\n";
		else out << "NU\n";
	}
}

int main()
{
	Solve();
	return 0;
}

