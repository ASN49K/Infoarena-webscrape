#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int EUC(int A, int B)
{
	if (!B) return A;
	return EUC(B, A%B);
}

int main()
{
	int a,b,n;
	fin>>n;
	for(int i = 0; i < n; i++)
	{
		fin>>a>>b;
		fout<<EUC(a,b)<<endl;
	}
	
	return 0;
}
