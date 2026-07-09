#include <fstream>
using namespace std;

//#define Assert(c) if(!(c)){*(int*)0 = 0;}
#define Assert(c)

int GCD(int a, int b)
{
	if(a < b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}

	while(b > 0)
	{
		Assert(a > b);
		int oldA = a;
		a = b;
		b = oldA % b;
	}

	Assert(b == 0);
	return a;
}

int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");

	int n;
	fin >> n;

	for(int i = 0; i < n; i++)
	{
		int a, b;
		fin >> a >> b;
		int g = GCD(a, b);
		fout << g << endl;
	}

	return 0;
}