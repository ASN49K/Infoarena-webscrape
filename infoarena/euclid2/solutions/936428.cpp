#include <fstream>
using namespace std;

int gcd(int a, int b)
{
	while (true) {
		if (a != 0) b %= a;
		else return b;
		if (b != 0) a %= b;
		else return a;
	}
}

int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	int n;
	fin >> n;
	int a, b;
	for (int i = 0; i < n; ++i) {
		fin >> a >> b;
		fout << gcd(a,b) << '\n';
	}
	return 0;
}
