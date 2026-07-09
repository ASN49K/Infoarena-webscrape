#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int bruteForceGCD(int a, int b) {
	int minNbr = min(a, b);
	for (int i = minNbr; i >= 1; --i) {
		if (a % i == 0 && b % i == 0) {
			return i;
		}
	}
}

int iterativeEuclideanGCD(int a, int b) {
	do {
		int temp = b % a;
		b = a;
		a = temp;
	} while (a != 0);
	return b;
}

int recursiveEuclideanGCD(int a, int b) {
	return (a == 0) ? b : recursiveEuclideanGCD(b % a, a);
}

int main() {
	int t;
	fin >> t;
	int a, b;
	while (t-- > 0) {
		fin >> a >> b;
		// fout << bruteForceGCD(a, b) << "\n";
		// fout << iterativeEuclideanGCD(a, b) << "\n";
		fout << recursiveEuclideanGCD(a, b) << "\n";
	}
    return 0;
}

