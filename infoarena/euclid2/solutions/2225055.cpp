#include<iostream>
#include<fstream>


std::ifstream fin("euclid2.in");
std::ofstream out("euclid2.out");


int gcd(int a, int b) {

	while (b) {
		int t = b;
		b = a % b;
		a = t;
	}

	return a;

}



int main() {


	int n, x, y;

	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> x >> y;
		out << gcd(x, y)<<std::endl;
	}

	return 0;
}




