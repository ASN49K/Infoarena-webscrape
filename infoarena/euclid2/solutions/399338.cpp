#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int Cmmdc ( int, int );
int a, b;

int main()
{
	int t;
	fin >> t;
	for ( int i = 0; i < t; ++i )
	{
		fin >> a >> b;
		fout << Cmmdc ( a, b ) << '\n';
	}
	fin.close();
	fout.close();
	return 0;
}

int Cmmdc ( int a, int b )
{
	if ( a == b ) return a;
	int rest;
	if ( b > a )
	{
		rest = a;
		a = b;
		b = rest;
	}
	
	do
	{
		rest = a % b;
		a = b;
		b = rest;
	} while ( rest );
	return a;
}
