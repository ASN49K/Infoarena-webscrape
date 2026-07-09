#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a, int b) {
	if (!b) return a;
	return euclid(b, a%b);
}

int main() {
	int t, a, b;
	in >> t;
	while (t--) {
		in >> a >> b;
		out << euclid(a, b) << '\n';
	}
	return 0;
}