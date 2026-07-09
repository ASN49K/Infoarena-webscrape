#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid.in");
ofstream g("euclid.out");

int	cmmdc(int a, int b) {
	
	int c;

	if (a == 0)
		return b;
	if (b == 0)
		return a;
	while (a != 0) {
		if (b > a) {
			b -= a;
			c = b / a;
			if (c*a == b)
				return a;
		}
		else {
			c = a / b;
			if (c*b == a)
				return b;
			a = -b;
		}
	}
	return b;
}

int main(){

	int nr, a, b;

	f >> nr;
	while (nr > 0) {
		f >> a >> b;
		g << cmmdc(a, b) << "\n";
		nr--;
	}

    return 0;
}

