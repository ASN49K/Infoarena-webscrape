#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b)
{
	while (b)
	{
		int aux = b;
		b = b % a;
		a = aux;
	}
	return a;
}

int main()
{
	int a, b, T;
	in >> T;
	while (T--)
	{
		in >> a >> b;
		out << cmmdc(a, b) << "\n";
	}
	
	return 0;
}
