#include <fstream>
using namespace std;

int cmmdc(int a, int b) {
	while (b != a)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;

}

int main() {
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	int t, i, a, b;
	in >> t;
	for (i = 1; i <= t; i++)
	{
		in >> a >> b;
		out << cmmdc(a, b) << '\n';
	}
}