#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ifstream fout("euclid2.out");

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
	    int result = gcd(a, b);
	    fout << result <<"\n";
	}
	return 0;
}