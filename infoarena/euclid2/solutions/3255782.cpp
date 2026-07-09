#include <fstream>

using namespace std;

ifstream cin ("euclid2.in");

ofstream cout ("euclid2.out");

int main () {

	int n;

	cin >> n;

	while (n--) {

		int a, b;

		cin >> a >> b;

		while (b) {

			int r = a % b;

			a = b;

			b = r;
		}

		cout << a << '\n';
	}

	return 0;
}