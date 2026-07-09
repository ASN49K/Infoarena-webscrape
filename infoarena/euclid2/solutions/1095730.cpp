#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;

//#define FILE "data"

#ifdef FILE
	ifstream f(string (string(FILE) + ".in").c_str());
	ofstream g(string (string(FILE) + ".out").c_str());
#endif
#ifndef FILE
	#define f cin
	#define g cout
#endif

int i, j, n, m;

int gcd (int x, int y) {
	if (y==0) return x;
	return gcd (y, x%y);
}

int main() {

	f >> n;
	while(n--) {
		f >> i >> j;
		g << gcd (i, j) << "\n";
	}

}
