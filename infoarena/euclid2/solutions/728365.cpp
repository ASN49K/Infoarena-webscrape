/* http://infoarena.ro/problema/euclid2 */
#include <fstream>

using std::ifstream;
using std::ofstream;

int main() {
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	
	int n, a, b, r;
	in >> n;
	while(n) {
		--n;
		in >> a >> b;
		do {
			r = a % b;
			a = b;
			b = r;
		} while(r != 0);
		
		out << a << '\n';
	}
}
