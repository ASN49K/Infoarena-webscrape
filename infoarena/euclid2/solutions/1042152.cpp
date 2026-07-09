#include <fstream>
using namespace std;



int GCD(int a, int b)
{
	if(!b) return a;
	return GCD(b, a % b);
}

int main(void)
{
	int T, A, B;
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");

	fin >> T;

	for(int i = 0; i < T; i++) {
		fin >> A >> B;
		fout << GCD(A, B) << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}
