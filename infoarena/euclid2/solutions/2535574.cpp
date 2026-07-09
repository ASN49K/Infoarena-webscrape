#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int greatestCommonDivisor(int a, int b)
{
	if (!b)
		return a;
	return greatestCommonDivisor(b, a % b);

}

int T, A, B;

int main()
{
	fin >> T;

	for ( ; T; --T)
	{
		fin >> A >> B;
		fout << greatestCommonDivisor(A, B) << endl;
	}

	return 0;
}