#include<iostream>
#include<fstream>
using namespace std;
int s,d,f,i;
int gcd(int a,int b) {
	if (!b) return a;     
	return gcd(b, a % b); 
}

ifstream aa("euclid2.in");
ofstream ss("euclid2.out");
int main() {
	aa >> s;
	for (i=1;i<=s;++i) {
		aa >> d >> f;
		ss << gcd(d,f) << "\n";
	}
	aa.close();
	ss.cloae();
	return 0;
}