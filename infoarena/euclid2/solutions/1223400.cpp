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

	int n, a, b;
	in >> n;


	for (int i = 0; i < n; i++){
		in >> a;
		in >> b;
		out << gcd(a, b) << endl;
	}

	in.close();
	out.close();

	return 0;
}