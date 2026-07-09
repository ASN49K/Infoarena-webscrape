#include <fstream>

using namespace std;


int euclid(int x, int y)
{
	if (!y)
		return x;
	return
	    euclid(y, x % y);
}

int main()
{
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");

	int t, x, y;

	in >> t;
	for (int i = 0; i < t; i++)
	{
		in >> x >> y;
		out << euclid(x, y) << "\n";
	}
}