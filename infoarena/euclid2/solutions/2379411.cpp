#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
	int x, a, b;
	in >> x;
	for (int i = 1; i <= x; i++)
	{
		in >> a >> b;
		while (b)
		{
			int rest = a % b;
			a = b;
			b = rest;
		}
		out << a << '\n';
	}
}