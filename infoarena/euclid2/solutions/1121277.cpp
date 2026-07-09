#include <iostream>
#include <fstream>
using namespace std;

int a, b;
int cmmdc(int a, int b) { return (b==0? a : cmmdc(b, a%b)); }

int main() {
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");

	f>>t;
	while(t--) {
		f>>a>>b;
		g<<cmmdc(a, b)<<"\n";
	}

	return 0;
}
