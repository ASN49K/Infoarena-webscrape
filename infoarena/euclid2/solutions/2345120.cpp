#include <fstream>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int t, a, b;

int cmmdc(int a, int b) {
	if(!b)
		return a;
	return (b, b % a);
}

int main() {
	cin >> t;
	while(t--) {
		cin >> a >> b;
		cout << cmmdc(a, b) << '\n';
	}
	return 0;
}
