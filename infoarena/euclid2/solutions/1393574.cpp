#include <fstream>
#include <iostream>
#include <utility>

using namespace std;

inline int cmmdc(int a, int b) {
	if (a > b)
		swap(a, b);
	int prev_b;
	while (b != 0) {
		prev_b = b;
		b = a % b;
		a = prev_b;
	}

	return prev_b;
}

int main(int argc, char *argv[])
{
	ifstream f{"euclid2.in"};
	ofstream g{"euclid2.out"};
	int n, a, b;
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> a >> b;
		g << cmmdc(a, b) << endl;
	}
	return 0;
}
