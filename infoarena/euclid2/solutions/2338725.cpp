#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int t, a, b;

int cmmdcRecursive(int a, int b) {
	if (b == 0) return a;
	else cmmdcRecursive(b, a % b);
}

int cmmdcIterative(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main() {
	in >> t;

	while (t --) {
		in >> a >> b;
		out << cmmdcIterative(a, b) << '\n';
	}
	return 0;
}