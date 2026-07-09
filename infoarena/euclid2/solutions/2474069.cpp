#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");

	int x, y,z,a;



	in >> x;
	in >> y;
	z = 1;


	while (z <= x && z<=y) {
		if (x % z == 0 && y % z == 0) {
			a = z;
		}

		z++;
	}
if(a!=1) {out << a << " ";}
else {out<<0;}

	return 0;
  }
