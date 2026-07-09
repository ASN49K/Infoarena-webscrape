#include <iostream>
#include <fstream>
#include <Bits.h>
#include <unordered_set>

std::ifstream fin("euclid2.in");
std::ofstream fout("euclid2.out");

int gcd(int a, int b) {
	if (!b)
		return a;
	return  gcd(b, a%b);
}


int main()
{
	int n,a,b;
	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> a >> b;
		int result = gcd(a, b);
		fout << result << '\n';
	}


	
	return 0;
}