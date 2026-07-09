#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b) {
	while(b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");
	
	int T, a, b;
	
	cin >> T;
	while(T--) {
		cin >> a >> b;
		cout << GCD(a, b) << "\n";
	}
	
	return 0;
}
