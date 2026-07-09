#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int cmmdc(int a, int b) {
	while (b) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int t;
int main() {
	cin >> t;
	for (int i = 1, a, b; i <= t; ++i)
		cin >> a >> b, cout << cmmdc(a, b) << "\n";
	return 0;
}