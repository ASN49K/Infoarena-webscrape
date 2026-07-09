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

ll gcdm(ll a, ll b) {
	if (!a) return b;
	else return (a % b, a);
}

int main() {
	int N;
	fin >> N;
	for (int a, b; N--; ) {
		fin >> a >> b;
		fout << gcdm(a, b) << "\n";
	}
	return 0;
}