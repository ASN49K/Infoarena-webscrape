#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int x, int y) {
	int r;

	while (y > 0) {
		r = x % y;
		x = y;
		y = r;
	}

	return x;
}

int main() {
	ifstream in;
	ofstream out;
	int n, i, x, y;

	in.open("euclid2.in");
	out.open("euclid2.out");
	
	in>>n;
	for (i = 0 ; i < n ; i ++) {
		in>>x>>y;
		out<<cmmdc(x, y)<<endl;
	}

	in.close();
	out.close();

	return 0;
}