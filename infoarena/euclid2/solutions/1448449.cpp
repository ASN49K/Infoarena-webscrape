#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

long cmmdc(long a, long b){
	if (!b) return a;
	else cmmdc(b, a%b);
}

int main(){

	ifstream ifile("euclid2.in");
	ofstream ofile("euclid2.out");
	long T, a, b;
	ifile >> T;

	while (T != 0){
		T--;
		ifile >> a >> b;
		ofile << cmmdc(a, b) << endl;
	}

	return 0;
}
