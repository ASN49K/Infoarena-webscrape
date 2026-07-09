#include <iostream>
#include <fstream>

using namespace std;

int gcd(int a, int b) {
	int aux;
	while (b != 0) {
		aux = b;
		b = a % b;
		a = aux;
	}
	return a;
}

int main(){
	ifstream input("euclid2.in");
	ofstream output("euclid2.out");
	int n;
	input >> n;
	int a, b, rez;
	for (int i = 0; i < n; i++) {
		input >> a >> b;
		rez = gcd(a, b);
		output << rez << endl;
	}
	return 0;
}