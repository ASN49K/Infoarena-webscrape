#include <iostream>
#include <fstream>
using namespace std;
int cmmdc(int a, int b){
	if(b == 0) return a;
	return cmmdc(b, a%b);
}
int main() {
	int t, a, b;
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	fin >> t;
	while (t>0){
		fin >> a >> b;
		fout << cmmdc(a, b) << endl;
		t--;
	}
	fin.close();
	fout.close();
	return 0;
}
