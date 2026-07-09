#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include<fstream>
using namespace std;

int main()
{
	//freopen("euclid2.in", "r", stdin);
	//freopen("euclid2.out", "w", stdout);
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	long long n, a, b,r;
	f >> n;
	for (; n;n--) {
		f >> a >> b;
		if (a < b) {
			a = a + b;
			b = a - b;
			a = a - b;
		}
		while (b) {
			r = a%b;
			a = b;
			b = r;
		}
		g << a << "\n";
	}
	return 0;
}