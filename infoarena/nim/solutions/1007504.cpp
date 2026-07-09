#include <fstream>
using namespace std;

ifstream in ("nim.in");
ofstream out ("nim.out");

int main() {
	int t;
	in >> t;
	while(t--){
		int n;
		in >> n;
		int xSum = 0;
		while(n--) {
			int tp;
			in >> tp;
			xSum^=tp;
		}
		if(xSum) {
			out << "DA\n";
		}
		else {
			out << "NU\n";
		}
	}
	return 0;
}