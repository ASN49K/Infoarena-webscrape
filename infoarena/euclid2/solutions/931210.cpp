#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a, int b) {
	if(b==0) return a;
	return cmmdc(b, a%b);
}

int main() {
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	
	int t, a, b;
	f>>t;
	while(t--) {
		f>>a>>b;
		g<<cmmdc(a, b)<<"\n";
	}

	return 0;
}
