#include <iostream>
#include <fstream>
using namespace std;

int A,B,N;

int EUC(int A, int B)
{
	if (!B) return A;
	return EUC(B, A%B);
}

int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");

	fin>>N;
	for(;N; --N)
	{
		fin>>A>>B;
		fout<<EUC(A,B)<<'\n';
	}
	
	return 0;
}
