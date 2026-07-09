#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b) {
	while (b != 0) {
		int r = a%b;
		a = b;
		b = r;
	}

	return a;
}

int main() {

	int t; f>>t;
	for (int i=1;i<=t;i++) {
		int a, b;
		f>>a>>b;
		g<<cmmdc(a,b)<<'\n';
	}

	return 0;
}
