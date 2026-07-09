#include <fstream>

int main()
{
	std::ifstream fin("euclid2.in");
	std::ofstream fout("euclid2.out");
	int cases, t, a, b;

	for (fin >> cases; cases; --cases)
	{
		fin >> a >> b;
		while (b)
		{
			t = b;
			b = a % b;
			a = t;
		}
		fout << a << std::endl;
	}

	return 0;
}
