#include <iostream>
#include <fstream>
using namespace std;

int T, A, B;

int GCD(int a, int b)
{
	if(b == 0) return a;
	return GCD(b, a % b);
}

int main(void)
{

	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");

	fin >> T;

	for(int i = 1; i <= T; i++) {
		fin >> A >> B;
		fout << GCD(A, B) << endl;
	}
}
