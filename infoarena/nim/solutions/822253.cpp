#include <fstream>
#include <iostream>

using namespace std;

int main() {
	ifstream cin("nim.in");
	ofstream cout("nim.out");
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int XOR = 0;
		while (n--) {
			int i;
			cin >> i;
			XOR ^= i;
		}
		cout << (XOR ? "DA" : "NU") << endl;
	}
	return 0;
}
