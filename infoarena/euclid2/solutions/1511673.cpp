#include <stdio.h>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

void gcd(int x, int y){

	int t;
	while(y > 0){
		t = y;
		y = x % y;
		x = t;
	}
	out << x << "\n";
}


void read(){

	int T, x, y;
	in >> T;
	for(int i = 0; i < T; ++i){
		in >> x >> y;
		gcd(x, y);
	}
}

int main(){

	read();
	return 0;
}