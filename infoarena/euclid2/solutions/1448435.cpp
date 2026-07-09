#include <iostream>
#include <fstream>

using namespace std;
int cmmdc(int a, int b){
	if (!b) return a;
	else cmmdc(b, a%b);
}

int main(){
	ifstream ifile("euclid2.in");
	ofstream ofile("euclid2.out");
	int T, a, b;
	ifile >> T;

	for (int i = 0; i < T; i++){
		ifile >> a >> b;
		ofile << cmmdc(a, b) << endl;
	}
}