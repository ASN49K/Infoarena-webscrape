#include<iostream>
#include<fstream>

using namespace std;

long T;
long long a, b;

long long cmmdc( long long a, long long b ) {
	long long r;
	while ( b != 0 ) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f >> T;
	for ( int i = 0; i < T; i ++ ) {
		f >> a;
		f >> b;
		g << cmmdc( a, b ) << '\n';
	}
	f.close();
	g.close();
	return 0;
}