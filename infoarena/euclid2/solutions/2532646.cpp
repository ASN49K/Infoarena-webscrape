#include <iostream>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a, int b) {
	if (!b) return a;
	else return euclid(b, a % b);
}

int main() {
	int a, b;
	in >> a >> b;
	if (a > b) cout << euclid(a, b);
	else cout << euclid(b, a);
	return 0;
}