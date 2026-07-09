#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
	int T;
	fin >> T;
	for(int i = 0;i<T;i++)
	{
		int a;
		fin >> a;
		int b, r;
		fin >> b;
		while(b != 0)
		{
			r = a % b;
			a = b;
			b = r;
		}
		fout << a << '\n';
	}
}
