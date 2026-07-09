#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("nim.in", "r", stdin);
	freopen("nim.out", "w", stdout);
s
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		
		int xorSum = 0;
		for (int i = 1; i <= N; i++) {
			int stones;
			cin >> stones;
			xorSum = xorSum ^ stones;
		}
		
		if (xorSum) cout << "DA\n";
		else cout << "NU\n";
	}

	return 0;
}