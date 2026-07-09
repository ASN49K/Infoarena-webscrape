#include<fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int t, a, b;

int euclid(int x, int y)
{
	if (!y) return x;
	if (x > y) return euclid(x - y, y);
	return euclid(x, y - x);
}

int main()
{
	in >> t;
	for (int i = 0; i < t; ++i)
	{
		in >> a >> b;
		out << euclid(a, b);
		out << endl;
	}
	return 0;
}
