#include<fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b)
{
	int r;
	while(a % b != 0)
	{
		r = a % b;
		a = b;
		b = r;
		
	}
	return b;
}

int main()
{
	int d, c, t;
	fin >> t;
	for(int i = 1; i <= t; i++)
	{
		fin >> d >> c;
	    fout << euclid(d, c) <<'/n';
	}
	fin.close();
	fout.close();
	return 0;
}

		