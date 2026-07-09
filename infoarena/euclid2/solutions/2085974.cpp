#include <fstream>


using namespace std;

int algoritmul_lui_euclid(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return algoritmul_lui_euclid(b, a % b);
	}
}

int main()
{
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");

	int T, a, b;
	in >> T;

	for (int i = 0; i < T; ++i)
	{
		in >> a >> b;
		out << algoritmul_lui_euclid(a, b) << endl;
	}
}