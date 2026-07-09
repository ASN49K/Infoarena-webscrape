#include <iostream>
#include <fstream>

using namespace std;

long cmmdc(long a, long b)
{
	long r;
	while (b != 0) {
		if (a < b) {
			r = b - a;
		}
		else {
			r = a - b;
			a = b;
		}
		b = r;
	}
	return a;
}

int main()
{
	long T;
	ifstream in("euclid2.in");
	in >> T;
	ofstream out("euclid2.out");
	for (long i = 0; i < T; i++) {
		long a, b;
		in >> a >> b;
		out << cmmdc(a, b) << endl;
	}
	in.close();
	out.close();
	return 0;
}
