#include <iostream>
#include <fstream>


std::ifstream f("euclid2.in");
std::ofstream g("euclid2.out");


int cmmdc(int x, int y) {
	if (y == 0) {
		return x;
	}
	return cmmdc(y, x % y);
}


int main()
{
	int t;
	f >> t;
	for (int i = 1; i <= t; i++) {
		int x, y;
		f >> x >> y;
		g << cmmdc(x, y) << '\n';
	}

	
	f.close();
	g.close();
	return 0;
}