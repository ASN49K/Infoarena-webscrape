#include <iostream>
using namespace std;
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