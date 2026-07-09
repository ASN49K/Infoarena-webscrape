#include <iostream>
#include <fstream> 
#include <algorithm>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main () {
	int t,a,b,i;
	fin>>t;
	for (i=1;i<=t; ++i) {
		fin>>a>>b;
		fout<<__gcd(a,b)<<endl;
	}
	return 0;
}
