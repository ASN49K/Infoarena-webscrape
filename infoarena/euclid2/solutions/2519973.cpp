#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream o("euclid2.out");
int euclid(int a, int b)
{
	while (a != b)
		if (a > b)
			a /= a - b;
		else
			b /= b - a;
	return a;
}
int main()
{
	int a, b, perechi;
	f >> perechi;
	while(perechi)
	{
		f >> a >> b;
		o << euclid(a, b) << endl;
		perechi--;
	}
	return 0;
}