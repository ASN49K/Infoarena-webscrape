#include <fstream>
using namespace std;

int gcd(int a, int b){
	if (!b) 
		return a;
	return gcd(b, a%b);
}



int main(){
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");

	unsigned n, a, b, cmmdc;
	in >> n;


	for (int i = n; i; --i){
		in >> a;
		in >> b;
		cmmdc = gcd(a, b);
		out << cmmdc << endl;
	}


	return 0;
}