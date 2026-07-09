#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main(){
	uint64_t t, a, b;
	fin>>t;
	while(t--){
		fin >> a >> b;
		fout << __gcd(a, b) << '\n';
	}
	return 0;
}
