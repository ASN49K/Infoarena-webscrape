#include <fstream>
using namespace std;

int T, A, B, r;

int GCD(int a, int b)
{
	if(!b) return a;
	return GCD(b, a % b);
}

int main(void)
{

	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");

	fin >> T;

	for(int i = 1; i <= T; i++) {
		fin >> A >> B;
		r = GCD(A, B);
		fout << r << endl;
	}
	fin.close();
	fout.close();
}
