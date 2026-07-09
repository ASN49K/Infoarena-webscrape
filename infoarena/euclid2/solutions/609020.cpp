#include <fstream.h>

typedef unsigned long tip;

tip euclid (tip a, tip b)
{
	while (a != b)
	{
		if (a == 0) return b;
		if (b == 0) return a;
		if (a > b)
		{
			a=a%b;
		}
		else b=b%a;
	}
	return a;
}

int main ()
{
	tip T, a, b, i;

	ifstream fin ("euclid2.in");
	ofstream fout ("euclid2.out");

	fin >> T;
	for (i = 0; i < T; i++)
	{
		fin >> a >> b;
		fout << euclid (a, b) <<"\n";
	}
	fin.close ();
	fout.close ();
	return 0;
}