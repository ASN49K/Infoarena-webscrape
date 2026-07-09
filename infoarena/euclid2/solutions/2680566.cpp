#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T, a, b;
int gcd(int a, int b) {
	  while(b != 0) {
	  	   int r = a % b;
	  	   a = b;
	  	   b = r;
	  }
	  return a;
}
int main() {
	fin >> T;
	for (; T; --T) {
	    fin >> a >> b;
	    fout << gcd(a, b) <<"\n";
	}
	return 0;
}