#include <iostream>
#include <vector>
#include <fstream>

#define ull unsigned long long
#define ll long long

#define minim(a, b) ((a < b) ? a : b);
#define maxim(a, b) ((a > b) ? a : b);

std::string fileName = "euclid2";

std::ifstream in(fileName + ".in");
std::ofstream out(fileName + ".out");

namespace utils {
	namespace cmmdc {
		int cmmdcScadere(int a, int b) {
			while (a != b) {
				if (a > b)
					a -= b;
				else
					b -= a;
			}
			return a;
		}
		int cmmdcRest(int a, int b) {
			int r;
			while (b) {
				r = a % b;
				a = b;
				b = r;
			}
			return a;
		}
		/*int cmmdcRestRecursiv(int a, int b) {
			
		}*/
		int cmmdcScadereRecursiv(int a, int b) {
			if (a == b)
				return a;
			if (a > b)
				return cmmdcScadereRecursiv(a - b, b);
			else
				return cmmdcScadereRecursiv(a, b - a);
		}
		int cmmdcIterativ(int a, int b) {
			int i;

			for (i = (a < b) ? a : b; i; i--)
				if (a % i == 0 && b % i == 0)
					return i;
		}
	}
}

void solve() {
	int a, b;
	in >> a >> b;
	out << utils::cmmdc::cmmdcRest(a, b) << std::endl;
}

int main() {
	int t;
	in >> t;
	while (t--) {
		solve();
	}
	return 0;
}