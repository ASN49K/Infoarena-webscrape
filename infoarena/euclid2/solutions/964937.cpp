#include<fstream>
#include<iostream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b) // 30 puncte cu functia recursiva
{
	if(a % b == 0)
		return b;
	else
		return gcd(b, a % b);
}

int gcd_iterativ(int a, int b)
{
	int aux;
	while(a % b != 0)
	{
		aux = b;
		b = a % b;
		a = aux;
	}
	return b;
}

int main()
{
	int i, t, a, b;
	fin >> t;
	for(i = 0; i < t; i++)
	{
		fin >> a >> b;
		fout << gcd_iterativ(a, b) << endl;
	}
	return 0;
}