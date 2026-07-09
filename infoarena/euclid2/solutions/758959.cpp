#include <fstream>
using namespace std;
int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	int a, b, n, x, i;
	fin>>n;
	for(i=1; i<=n; i++)
	{
		fin>>a>>b;
		if (b<a)
		{
			x=b;
			b=a;
			a=x;
		}
		while (b != 0)
		{
			a = a%b;
			x=b;
			b=a;
			a=x;
		}
		fout<<a<<"\n";
	}
	return 0;
}
