#include <fstream>

using namespace std;

int t, n, i, x, s;
int main() {
	ifstream f("nim.in");
	ofstream g("nim.out");
	f>>t;
	for (;t;t--) {
		f>>n;
		s = 0;
		for (i=1;i<=n;i++) {
			f >> x;
			s ^= x;
		}
		if (s)
			g<<"DA\n";
		else
			g<<"NU\n";
	}
	return 0;
}