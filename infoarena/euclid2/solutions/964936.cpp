#include<fstream>
#include<iostream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b)
{
	if(a % b == 0)
		return b;
	else
		return gcd(b, a % b);
}

int main()
{
	int i, t, a, b;
	fin >> t;
	for(i = 0; i < t; i++)
	{
		fin >> a >> b;
		fout << gcd(a, b) << endl;
	}
	return 0;
}