#include<iostream>
using namespace std;

int gcd(int a, int b) {
	if (!b)
		return a;
	return gcd(b, a % b);
}

int main() {
	int T, a, b;

	freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    cin >> T;
    for ( ; T > 0; --T) {
    	cin >> a >> b;
    	cout << gcd(a, b) << endl;
	}

	return 0;
}
