#include <iostream>
#include <fstream>
using namespace std;
int main() {
	long t, a, b, i, r;
	ifstream f; f.open("euclid2.in");
	ofstream g; g.open("euclid2.out");
	f>>t;
	for(i=1; i<=t; i++) {
		f>>a>>b;
		r=a%b;
		while(r!=0) {
			a=b;
			b=r;
			r=a%b;
		}
		g<<b<<endl;
	}
	f.close();
	g.close();
	return 0;
}
			