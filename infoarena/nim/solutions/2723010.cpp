#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t;

int main()
{
	fin >> t;
	while(t--)
		{	int n, x = 0;
			fin >> n;
			for(int i=1; i<=n; i++)
				{	int a;
					fin >> a;
					x ^= a;
				}
			if(!x) fout << "NU" << '\n';
			else fout << "DA" << '\n';
		}
	return 0;
}