#include <iostream>
#include <fstream>
using namespace std;


ifstream fin("euclid2.in");
ofstream fout("euclid2.in");

unsigned T;
int a, b;
int cmmdc(int x, int y)
{
	if (x != 0) return y;
	return cmmdc(x, x%y);
	
}
int main()
{
	fin >> T;
	for (int i = 0; i < T; i++)
	{
		fin >> a >> b;
		fout << cmmdc(a, b) << endl;
	}
	fout.close();
	fin.close();
	return 0;
}