#include <iostream>
#include <fstream>

using namespace std;

long cmmdc(long a, long b)
{
	if (a == 0 || b == 0)
		return 1;
	long r = 1;
	while (r != 0) {
		r = a % b;
		a = b;
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
		out << cmmdc(a, b) << "\n";
	}
	in.close();
	out.close();
	return 0;
}
