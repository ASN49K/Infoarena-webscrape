/* reads from euclid.in file
   n on the first line, then n pairs of numbers
   calculates the greatest common divisor for each
   outputs in euclid.out
   complexity ~= O(N*log(max(nr1,nr2))
*/

#include <iostream>
#include <fstream>

using namespace std;

typedef long long ll;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

ll gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}

int main() {
	int N;
	fin >> N;
	for (int a, b; N--; ) {
		fin >> a >> b;
		fout << gcd(a, b) << "\n";
	}
	return 0;
}