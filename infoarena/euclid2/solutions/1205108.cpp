#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int a, int b ) {
	if ( a == 0) 
		return b;
	return cmmdc(b%a, a);
}

int main() {
	int t;
	ifstream f ("euclid2.in");
	ofstream g ("euclid2.out");
	f >> t ; 
	for (; t; t--) {
		int a, b;
		f >> a >> b;
		if ( a > b ) 
			a = (a ^ b) ^ ( b = a );
		int rez = cmmdc(a, b);
		g << rez << '\n';
	}
	g.close();
	f.close();
}