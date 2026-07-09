#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
	clock_t start = clock();
	ifstream in ("euclid2.in");
	ofstream out ("euclid2.out");
	int t, x, y, aux;
	in >> t;
	for (; t; --t)
	{
		in >> x >> y;
		if (x == 0) {out << y << "\n"; continue; }
		while (y > 0)
		{
			aux = x;
			x = y;
			y = aux % x;
		}
		out << x << "\n";
	}
	in.close();
	out.close();
	clock_t stop = clock();
	cout << (double) (stop-start) / CLOCKS_PER_SEC << endl;
	return 0;
}
