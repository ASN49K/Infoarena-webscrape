#include <fstream>

using namespace std;

int main () {
	ifstream f ("nim.in");
	ofstream g ("nim.out");
	unsigned int t, n, x, s;
	for (f >> t; t; -- t ) {
		s = 0;
		for (f >> n; n; -- n) {
			f >> x;
			s ^= x;
		}
		if (s) {
			g << "DA\n";
		}
		else {
			g << "NU\n";
		}
	}
	f.close ();
	g.close ();
	return 0;
}
