#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;

		while (b) {
			int aux = b;
			b = a % b;
			a = aux;
		}

		cout << a << "\n";
	}

	return 0;
}