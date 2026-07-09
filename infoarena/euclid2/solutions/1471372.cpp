#include <iostream>
#include <fstream>

using namespace std;

int GCD(int a, int b){
	if (b == 0)
		return a;
	else
		return GCD(b, a%b);
}

int main() {
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");

	int n, i, x, y;
	f >> n;
	for (i = 0; i < n; ++i) {
		f >> x >> y;
		g << GCD(x, y) << "\n";
	}

	f.close();
	g.close();
	return 0;
}