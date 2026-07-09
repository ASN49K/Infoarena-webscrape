#include <fstream>
using namespace std;
int main() {
	ifstream fi("euclid2.in");
	ofstream fo("euclid2.out");
	int t;
	fi >> t;
	for (int i = 1; i <= t; i++) {
 		int a, b;
		fi >> a >> b;
		while (a != 0 && b != 0) {
			if (a > b) a %= b;
			else b %= a;
		}
		fo << a+b << '\n';
	}
	return 0;
}