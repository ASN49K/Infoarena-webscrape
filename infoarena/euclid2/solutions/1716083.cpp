#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, a, b,r;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
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
		cout << a << "\n";
		cout.flush();
	}
	return 0;
}