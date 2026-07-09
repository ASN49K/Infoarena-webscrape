#include <fstream>
using namespace std;

//#define Assert(c) if(!(c)){*(int*)0 = 0;}
#define Assert(c)

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
		while(b > 0)
		{
			int r = a % b;
			a = b;
			b = r;
		}

		fout << a << endl;
	}

	return 0;
}