#include <fstream>
using namespace std;

int gcd(int a, int b){
	int r;
	while(b){
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}



int main(){
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");

	int n, a, b;
	in >> n;


	for (int i = n; i; --i){
		in >> a;
		in >> b;
		out << gcd(a, b) << endl;
	}

	in.close();
	out.close();

	return 0;
}