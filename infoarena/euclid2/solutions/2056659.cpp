#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int a, int b);

int main()
{
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");

	int n, a, b;

	in >> n;

	for(int i = 0; i < n; i++) {
		in >> a >> b;
		out << cmmdc(a,b) << '\n';
	}

	return 0;
}

int cmmdc(int a, int b)
{
	int c;

	while(b) {
		c = b;
		b = a % b;
		a = c;
	}

	return a;
}
