#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a, int b) {
	if (a == 0) {
		return b;
	}
	return euclid(b % a, a);
}

int main()
{
	int n, a, b;
	in >> n;
	while (n) {
		in >> a >> b;
		if (a < b) {
			out << euclid(a, b) << '\n';
		}
		else {
			out << euclid(b, a) << '\n';
		}
		n--;
	}
    return 0;
}

