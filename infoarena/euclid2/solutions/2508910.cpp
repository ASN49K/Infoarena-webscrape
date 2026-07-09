#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdcEuclid(long long a, long long b) {
	while (a != b)
		if (a > b) a = a - b;
		else b = b - a;
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