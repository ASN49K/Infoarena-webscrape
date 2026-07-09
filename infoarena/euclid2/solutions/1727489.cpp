#include <fstream>

using namespace std;

int main() {
	int a, b, c;
	ifstream f("euclid2.in");
	ofstream g("eudlid2.out");

	f >> a; // T
	while (f >> a >> b) {
		while (b) {
			c = a % b;
			a = b;
			b = c;
		}
		g << a << endl;
	}
	f.close();
	g.close();

	return 0;
}
