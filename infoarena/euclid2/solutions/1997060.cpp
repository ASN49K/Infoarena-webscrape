#include <fstream>
using namespace std;

int lnko(int a, int b) {
	if (!b) return a;
	else return lnko(b, a%b);
}

int main() {
	int T;
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	in >> T;
	for (;T;--T) {
		int a, b;
		in >> a >> b;
		out << lnko(a, b) << "\n";
	}
	in.close();
	out.close();
	//return 0;
}