#include <fstream>
using namespace std;

int cmmdc(int a, int b);

int main(){
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	int t, x, y;
	in >> t;
	for (int i = 0; i < t; i++){
		in >> x >> y;
		out << cmmdc(x, y) << "\n";
	}
	return 0;
}

int cmmdc(int a, int b){
	while (a>0){
		b %= a;
		a = b - a;
		b -= a;
		a += b;
	}
	return b;
}