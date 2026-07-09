#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("euclid.in");
ofstream g ("euclid.out");

int euclid(int x, int y) {
	int t;
	while (x % y) {
		t = x % y;
		x = y;
		y = t; 
	}
	return y;
}

int main() {
	int n, x, y;
	f >> n;
	
	for (int i = 1; i <= n; i++) {
		f >> x >> y;
		g << euclid(x, y) << '\n';
	}

	return 0;
}