#include <fstream>

using std::ifstream;
using std::ofstream;

int main() {
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	
	int n, a, b;
	in >> n;
	while(n) {
		--n;
		in >> a >> b;
		int d, i, r = 0; // deimpartit, impartitor, rest
		if(a < b) {
			d = a;
			i = b;
		} else {
			d = b;
			i = a;
		}
		
		do {
			r = d % i;
			d = i;
			i = r;
		} while(r != 0);
		
		out << d << '\n';
	}
}