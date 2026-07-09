#include <fstream>

using namespace std;

int main()
{
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");

	int n; in >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b; in >> a >> b;

		while (a != 0 && b != 0)
		{
			(a > b) ? a %= b : b %= a;
		}

		a != 0 ? out << a : out << b;
		out << "\n";
	}

	return 0;
}