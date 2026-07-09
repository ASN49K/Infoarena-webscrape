#include <fstream>
using namespace std;

ifstream cin("sum.in");
ofstream cout("sum.out");

int GCD(int a, int b) {

	if (!b) return a;
	return GCD(b, a % b);

}

int main() {

	int n, x, y;
	cin >> n;
	while (n != 0) {
		cin >> x >> y;
		cout << GCD(x, y) << endl;
		n--;
	}
	return 0;
}