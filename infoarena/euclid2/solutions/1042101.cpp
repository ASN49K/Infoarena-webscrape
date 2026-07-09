#include <fstream>
using namespace std;

int T, A, B, r;

int GCD(int a, int b)
{
	for(int i = min(a, b); i > 1; i--) {
		if(a % i == 0 && a % b == 0) {
			return i;
		}
	}
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
