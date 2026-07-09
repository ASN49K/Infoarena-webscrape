#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream o("euclid2.out");
int euclid(int a, int b)
{
	if (b == 0)
		return a;
	else
		return euclid(b, a % b);
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