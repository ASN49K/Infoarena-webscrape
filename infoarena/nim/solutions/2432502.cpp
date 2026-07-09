#include <assert.h>
#include <fstream>

int main() {
	int t, n, element;
	std::ifstream cin("nim.in");
	std::ofstream cout("nim.out");
	std::ios::sync_with_stdio(false);
	cin >> t;
	assert(1 <= t && t <= 100);

	for (; t ; --t) {
		cin >> n;
		int xorsum = 0;
		for (int i = 0 ; i < n ; ++i) {
			cin >> element;
			xorsum ^= element;
		}

		if (xorsum) {
			cout << "DA\n";
		} else {
			cout << "NU\n";
		}
	}

	return 0;
}