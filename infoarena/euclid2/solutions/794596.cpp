#include <iostream>
#include <fstream>

using namespace std;

long gcd(long a,long b)
{
	long r;
	while (b != 0)
	{
		r = b;
		b = a % b;
		a = r;
	}
	return a;
}

int main()
{
	long N,a,b;
	fstream fin,fout;

	fin.open("euclid2.in",ios::in);
	fout.open("euclid2.out",ios::out);

	fin >> N;
	for( ; N ; --N)
	{
		fin >> a >> b;
		fout << gcd(a,b) << endl;
	}

	fin.close();
	fout.close();
	return 0;
}