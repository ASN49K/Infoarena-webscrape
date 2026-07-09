#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a, int b) {
	int r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int main() {
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");

	int n;
	int a, b;

	in >> n;
	for(int i=0;i<n;i++){
		in >> a >> b;
		out << cmmdc(a, b) << endl;
	}

	in.close();
	out.close();
	return 0;
}
