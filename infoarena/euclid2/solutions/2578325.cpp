#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int cmmdc(int a, int b)
{
	if( b == 0 )
		return a;
	return cmmdc(b, a%b);
}

int main ()
{
	int T,a,b;
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	fin >> T; 
	for (int i=0; i<T; i++)
	{
		fin>>a>>b;
		fout<<cmmdc(a, b)<<'\n';
	}
return 0;
}