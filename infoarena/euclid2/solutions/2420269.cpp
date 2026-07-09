#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
	int n;
	fin >> n;

	for(int i = 0; i < n; i++)
	{
		int a, b;
		fin >> a >> b;
		while(a % b)
		{
			int r = a % b;
			a = b;
			b = r;
		}

		fout << b << endl;
	}

	return 0;
}