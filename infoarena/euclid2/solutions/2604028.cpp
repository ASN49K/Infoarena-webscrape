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

int main() {

	int a, b, t;
	fin >> t;
	while(t --) {
		fin >> a >> b;
		fout << sol1(a, b) << '\n';
	}
	return 0;
}