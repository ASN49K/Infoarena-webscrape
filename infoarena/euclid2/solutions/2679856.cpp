#include <fstream>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int cmmdc(int a, int b) {
	if (b > a)
		swap(b, a);
	return a % b;
}
int main() {
	int a, b;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		cout << cmmdc(a, b) << "\n";
	}
}