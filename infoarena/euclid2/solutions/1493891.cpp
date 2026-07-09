#include <fstream>
#define ui unsigned int
using namespace std;

ui cmmdc(ui a, ui b) {
	if (b == 0) {
		return a;
	}
	return cmmdc(b, a % b);
}

int main() {
	ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		ui a, b;
		cin >> a >> b;
		cout << cmmdc(a, b) << '\n';
	}

	return 0;
}
