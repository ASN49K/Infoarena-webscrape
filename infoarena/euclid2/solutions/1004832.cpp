#include <fstream>
using namespace std;

size_t cmmdc(size_t a, size_t b) {
	size_t r;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() 
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");

	size_t tries;
	for (fin >> tries; tries; --tries) {
		size_t a, b;
		fin >> a >> b;
		fout << cmmdc(a, b) << '\n';
	}

	return 0;
}
