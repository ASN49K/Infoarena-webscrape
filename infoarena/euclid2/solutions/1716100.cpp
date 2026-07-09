//#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	//ifstream f("euclid2.in");
	//ofstream g("euclid2.out");
	long long n, a, b,r;
	cin>> n;
	for (; n;n--) {
		cin>> a >> b;
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
		cout<< a << "\n";
	}
	return 0;
}