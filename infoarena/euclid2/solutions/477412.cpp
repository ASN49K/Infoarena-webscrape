#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream in ("euclid2.in");
	ofstream out ("euclid2.out");
	int t, x, y, aux;
	in >> t;
	for (; t; --t)
	{
		in >> x >> y;
		if (x == 0) {out << y << endl; continue; }
		while (y > 0)
		{
			aux = x;
			x = y;
			y = aux % x;
		}
		out << x << endl;
	}
	in.close();
	out.close();
	return 0;
}
