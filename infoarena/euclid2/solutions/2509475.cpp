#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdcEuclid(long long a, long long b) {
	while (b != 0)
	{
		long long r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int T;
	long long a, b;
	fin >> T;
	for (int i = 1; i <= T; i++)
	{
		fin >> a >> b;
		fout << cmmdcEuclid(a, b) << "\n";
	}
	
}