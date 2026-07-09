#include <fstream>
#include <iostream>

using namespace std;

int cmmdc(int a, int b){
	if(b > a)
		swap(a,b);

	int r = a % b;

	if(r == 0)
		return b;
	else
		return cmmdc(b, r);

}

int main(){
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	int t, a, b;
	fin >> t;
	for(int i = 0; i < t; ++i){
		fin >> a >> b;
		fout << cmmdc(a, b) << "\n";
	}

}