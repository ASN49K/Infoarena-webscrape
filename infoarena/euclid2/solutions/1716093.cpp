#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	FILE*f=freopen("euclid2.in", "r", stdin);
	FILE*g=freopen("euclid2.out", "w", stdout);
	int n, a, b,r;
	cin >> n;
	for (; n;n--) {
		cin >> a >> b;
		
		while (b) {
			r = a%b;
			a = b;
			b = r;
		}
		cout << a << "\n";
	}
	return 0;
}