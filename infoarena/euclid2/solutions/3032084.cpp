#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
	ifstream cin("euclid2.in");
  	ofstream cout("euclid2.out");
  	int t, a, b;
  	cin >> t;
  	for (int i = 0; i < t; ++i) {
  		cin >> a >> b;
  		cout << gcd(a, b) << "\n";
  	}
  	cout.close();
	return 0;
}
