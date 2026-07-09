#include <fstream>

using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

int t, n, s, nr;

int main() {
	in >> t;

	while (t --) {
		in >> n;
		s = 0;
		for (int i = 1; i <= n; ++ i) {
			in >> nr;
			s ^= nr;
		}

		if (s == 0)
			out << "NU\n";
		else
			out << "DA\n";
	}

	return 0;
}
