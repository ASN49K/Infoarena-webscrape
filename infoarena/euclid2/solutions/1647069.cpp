// euclid2.cpp : Defines the entry point for the console application.
//
//#include "stdafx.h";
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int rez;

int euclid(int a, int b)
{
	rez = -1;
	while (a && b)
	{
		if (a >= b) {
			a = a - b;
		}
		else {
			b = b - a;
		}
	}
	if (a)
		rez = a;
	else
		rez = b;
	return rez;
}

int main() {
	int a, b, len;
	fin >> len;
	for (int i = 0;i < len;i++)
	{
		fin >> a >> b;
		fout << euclid(a, b) << '\n';
	}
	return 0;
}
