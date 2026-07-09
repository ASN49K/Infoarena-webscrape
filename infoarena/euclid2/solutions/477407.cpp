#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream in ("euclid2.in");
	ofstream out ("euclid2.out");
	int t, x, y;
	in >> t;
	for (int i = 0; i < t; i++)
	{
		in >> x >> y;
		while (x > 0 && y > 0)
			x > y ? x = x % y : y = y % x;
		out << (x > 0 ? x : y) << endl;
	}
	in.close();
	out.close();
}
