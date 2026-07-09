#include <fstream>

using namespace std;

int cmmdc(int a, int b)
{
	if (b == 0) return a;
	return cmmdc(b, a % b);
}

int main()
{
	int t, x, y;

	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	for (int i = 0; i < t; i++)
	{
		in >> x >> y;
		out << cmmdc(x, y);
	}
	in.close();
	out.close();

	return 0;
}