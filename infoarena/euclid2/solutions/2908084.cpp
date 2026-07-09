#include <fstream>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int cmmdc(int a, int b);
int t, x, y;

int main() {

	cin >> t;

	for (; t; t--) {
		cin >> x >> y;
		cout << cmmdc(x, y) << '\n';
	}
	
	return 0;
}

int cmmdc(int a, int b) {
	int r;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}