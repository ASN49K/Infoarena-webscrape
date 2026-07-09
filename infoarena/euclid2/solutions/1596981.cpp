#include <fstream>
#include <iostream>
using namespace std;
int cmmdc(int x, int y){
	int z;
	while (y){
		z = y;
		y = x%y;
		x = z;
	}
	return x;
}
int main() {
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int T, a, b, i;
	f >> T;
	for (i = 1; i <= T; i++){
		f >> a >> b;
		g << cmmdc(a, b) << "\n";
	}
	
}
