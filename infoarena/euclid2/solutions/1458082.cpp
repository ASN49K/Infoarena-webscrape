#include<iostream>
#include<fstream>
using namespace std;

unsigned euclid(unsigned a, unsigned b)
{
	unsigned r;
	while (b)
	{
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	unsigned T;
	ifstream f;
	ofstream g;
	f >> T;
	for (int i = 1; i <= T; ++i)
	{
		unsigned x, y;
		f >> x >> y;
		cout << euclid(x, y) << '\n';
	}
	return 0;
}