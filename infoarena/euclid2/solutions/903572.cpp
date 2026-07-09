#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

inline int euclid(int a, int b) {
	if (b == 0)
		return a;
	return euclid(b, a%b);
}

int main() {
	int t;
	in >> t;

	while (t--) {
		int a, b;
		in >> a >> b;

		out << euclid(a, b) << "\n";
	}

	return 0;
}
