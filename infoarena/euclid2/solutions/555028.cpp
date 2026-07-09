#include <fstream>
using namespace std;

int main()
{
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	
	int T;
	in >> T;

	for (int i = 1; i <= T; i++)
	{
		int x, y;
		in >> x >> y;

		while (y)
		{
			int t = y;
			y = x % y;
			x = t;
		}

		out << x << '\n';
	}
}
