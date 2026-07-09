
#include<fstream>
#include <iostream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
	int T, a, b,r;
	fin >> T;
	for (int i = 1; i <= T; i++)
	{
		fin >> a >> b;
		while (b)
		{
			r = b;
			b = a % b;
			a = r;
		}
		fout << a <<'\n';
	}
}

