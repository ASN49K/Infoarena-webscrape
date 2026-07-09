#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream o("euclid2.out");
int main()
{
	int a, b, perechi;
	f >> perechi;
	while(perechi)
	{
		f >> a >> b;
		while (b != 0)
		{
			int c = b;
			b = a % b;
			a = c;
		}
		o << a << '\n';
		perechi--;
	}
	return 0;
}