#include <bits/stdc++.h>
#define newline "\n"
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
	for (int i = 1; i <= T; ++i) {
		fin >> a >> b;
		fout << gcd(a, b) << newline;
	}
	return 0;
}