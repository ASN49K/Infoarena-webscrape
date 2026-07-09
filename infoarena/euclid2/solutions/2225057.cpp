#include<iostream>
#include<fstream>


std::ifstream fin("euclid2.in");
std::ofstream out("euclid2.out");


int gcd(int a, int b) {

	if (!b) return a;
	return gcd(b, a % b);

}



int main() {


	int n, x, y;

	fin >> n;
	for (;n;n--){
		fin >> x >> y;
		out << gcd(x, y)<<std::endl;
	}

	return 0;
}




