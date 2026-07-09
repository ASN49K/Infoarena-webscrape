#include<fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
	int a, b, t, r;
	fin >> t;
	for(int i = 1; i <= t; i++)
	{
		fin >> a >> b;
		while(a % b != 0)
		{
			r = a % b;
			a = b;
			b = r;
		}
		fout << b << '\n';
		
	}
	fin.close();
	fout.close();
	return 0;
}

		