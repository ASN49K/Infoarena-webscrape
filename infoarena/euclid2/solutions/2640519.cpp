#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int x, int y) {
	int r;
	while (y) {
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}
int main() {
	int cnt;
	f >> cnt;
	while (cnt--) {
		int a, b;
		f >> a >> b;
		g << cmmdc(a, b) << "\n";
	}
	return 0;
}