#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout("euclid2.out");

int sol1(int a,int b) {
	int minim = min(a, b);
	for (int i = minim;i >= 1;i --)
		if (a % i == 0 and b % i == 0)
			return i;
}

int sol2(int a, int b) {
	if (a == b)
		return a;
	else
		if (a > b)
			return sol2(a - b, b);
		else
			return sol2(a, b - a);
}

int sol3(int a, int b) {
	if (b == 0)
		return a;
	return sol3(b, a % b);
}
int main() {

	int a, b, t;
	fin >> t;
	while(t --) {
		fin >> a >> b;
		if (b > a) swap(a, b);
		fout << sol3(a, b) << '\n';
	}
	return 0;
}