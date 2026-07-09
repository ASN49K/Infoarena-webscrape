#include <fstream>
using namespace std;

int main()
{
	unsigned long long int a, b, r, t;
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	fin >> t;
	for(unsigned long long int i=0; i<t; i++)
	{
		fin >> a >> b;
		while (b != 0)
		{
			r = b;
			b = a % b;
			a = r;
		}
		fout << a << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}
