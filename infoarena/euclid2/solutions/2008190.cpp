#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int i, t;
	int a, b, r;
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");

	fin >> t;

	for (i = 0; i < t; i++)
	{
		fin >> a >> b;
		if (a < b)
		{

		}
		while (b)
		{
			r = a%b;
			a = b;
			b = r;
		}
		fout << a << "\n";
	}

	fout.close();
	fin.close();
	return 0;
}
