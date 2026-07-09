#include <bits/stdc++.h>

using namespace std;
	
int main() {
	#ifdef BLAT
		freopen("input", "r", stdin);
	#else
		freopen("euclid2.in", "r", stdin);
		freopen("euclid2.out", "w", stdout);
	#endif

	int t;
	cin >> t;

	while(t--) {
		int a, b;
		cin >> a >> b;

		cout << __gcd(a, b) << '\n';
	}
	return 0;
}
