#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t, a, b;

int cmmdc(int a, int b){
	if(b==0){
		return a;
	}
	if(b==1){
		return 1;
	}
	return cmmdc(b, a%b);
}

int main(){
	fin>>t;
	for(int i = 0; i < t; ++i){
		fin >> a >> b;
		fout << cmmdc(a, b) << '\n';
	}
}