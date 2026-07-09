//#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#define nmax 2000005
using namespace std;
ifstream f("euclid2.in");
ofstream o("euclid2.out");

int a, b;
int t;
int euclid(int x, int y)
{
	if (x < y)
	{
		swap(x, y);
	}

	while (y)
	{
		int	rest = x % y;
		x = y;
		y = rest;
	}

	return x;
}



int main()
{
	f >> t;
	while (t--)
	{
		f >> a >> b;
		o << euclid(a, b) << "\n";
	}

}