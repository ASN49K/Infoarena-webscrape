#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int n, x, s;

void test()
{
	fin >> n;
	s = 0;
	for (int i = 1; i <= n; i++)
	{
		fin >> x;
		s ^= x;
	}
	if (s != 0)
		fout << "DA\n";
	else
		fout << "NU\n";	
}

int main() 
{
	int t;
	fin >> t;
	while (t--)
		test();
	
	fin.close();
	fout.close();
	return 0;
}