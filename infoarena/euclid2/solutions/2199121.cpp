#include <fstream>

using namespace std;

int euclid(int a, int b)
{
	if (a < b)
	{
		a ^= b;
		b ^= a;
		a ^= b;
	}

	// a o sa fie ala mai mare

	while (b != 1 && a % b != 0)
	{
		a /= b;
		a ^= b;
		b ^= a;
		a ^= b;
	}

	return b;
}

int main()
{
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");

	int n;
	in >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		in >> a >> b;

		out << euclid(a, b) << endl;
	}

	return 0;
}